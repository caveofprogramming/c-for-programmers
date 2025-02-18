#include <assert.h>
#include <stdlib.h>
#include "include/graphics.h"

static void dprint(const char *message)
{
    #ifdef DEBUG
	fprintf(stderr, "%s\n", message);
    #endif
}

graphics_t *graphics_init(char title[], int width, int height)
{
    graphics_t *g = (graphics_t *)malloc(sizeof(graphics_t));
    memset(g, 0, sizeof(graphics_t));

    if(g == NULL)
    {
        dprint("Unable to allocate buffer memory.");
        return NULL;
    }

    g->width = width;
    g->height = height;

    if (SDL_Init(SDL_INIT_VIDEO) == false) {
		dprint("Unable to initialise video.");
		return NULL;
	}

	g->window = SDL_CreateWindow(title, width, height, 0);

	if (g->window == NULL) 
	{
		dprint(SDL_GetError());
		return NULL;
	}

    g->screen = SDL_GetWindowSurface(g->window);

    if (g->screen == NULL) 
	{
		dprint(SDL_GetError());
		return NULL;
	}

    //SDL_PIXELFORMAT_RGB888
    g->pixels = SDL_CreateSurface(width, height, SDL_PIXELFORMAT_RGBX32);

    if (g->pixels == NULL) 
	{
		dprint(SDL_GetError());
		return NULL;
	}
    
	g->n_buffer_bytes = width * height * sizeof(uint32_t);
    
	g->buffer = (uint32_t *)malloc(g->n_buffer_bytes);

	if(g->buffer == NULL)
	{
		dprint("Unable to create buffer.\n");
		return NULL;
	}

	memset(g->buffer, 0, g->n_buffer_bytes);

    g->back_buffer = (uint32_t *)malloc(g->n_buffer_bytes);

	if(g->back_buffer == NULL)
	{
		dprint("Unable to create back buffer.\n");
		return NULL;
	}

	memset(g->back_buffer, 0, g->n_buffer_bytes);

    return g;
}


/*
 * Box blur.
 * For each pixel, sum rgb values for that and the 8 surrounding pixels,
 * then divide by 9 and set the new pixel values to the result.
 */


static void horizontal_blur(uint32_t *input, uint32_t *output, int width, int height)
{
    for (int y = 0; y < height; y++) 
    {
        int sumr = 0, sumg = 0, sumb = 0;

        for (int x = 0; x < width; x++) 
        {
            if(x > 1)
            {
                // Subtract values of leftmost pixel
                uint32_t color = input[y * width + (x - 2)];
                sumr -= RED(color);
                sumg -= GREEN(color);
                sumb -= BLUE(color);
            }

            if(x == 0)
            {
                // Add this pixel
                uint32_t color = input[y * width];
                sumr += RED(color);
                sumg += GREEN(color);
                sumb += BLUE(color);
            }

            if(x < width - 1)
            {
                // Add values of new pixel to the right.
                uint32_t color = input[y * width + (x + 1)];
                sumr += RED(color);
                sumg += GREEN(color);
                sumb += BLUE(color);
            }

            int count = x == 0 || x == width-1 ? 2: 3;
            int index = y * width + x;
            output[index] = RGB(sumr/count, sumg/count, sumb/count);      
        }
    }
}


static void vertical_blur(uint32_t *input, uint32_t *output, int width, int height)
{
    for (int x = 0; x < width; x++) 
    {
        int sumr = 0, sumg = 0, sumb = 0;

        for (int y = 0; y < height; y++) 
        {
            if(y > 1)
            {
                // Subtract values of pixel that drops off top edge
                uint32_t color = input[(y - 2) * width + x];
                sumr -= RED(color);
                sumg -= GREEN(color);
                sumb -= BLUE(color);
            }

            if(y == 0)
            {
                // Add this pixel
                uint32_t color = input[x];
                sumr += RED(color);
                sumg += GREEN(color);
                sumb += BLUE(color);
            }

            if(y < height-1)
            {
                // Add values of new pixel below.
                uint32_t color = input[(y+1) * width + x];
                sumr += RED(color);
                sumg += GREEN(color);
                sumb += BLUE(color);
            }

            int count = y == 0 || y == height-1 ? 2: 3;
            int index = y * width + x;
            output[index] = RGB(sumr/count, sumg/count, sumb/count);  
        }
    }
}

void transpose(uint32_t *input, uint32_t *output, int input_width, int input_height)
{
    for(int y=0; y<input_height; ++y)
    {
        for(int x=0; x<input_width; ++x)
        {
            int index = y*input_width + x;
            int new_index = x*input_height + y;

            output[new_index] = input[index];
        }
    }
}

/*
 * These tests assume no floating point division was used; only integer division.
 */
void graphics_test_blur()
{
    const int width = 4;
    const int height = 5;

    uint32_t TESTDATA_HORIZONTAL[20] = 
    {
            0x4fde9700,  0xec6cbd00,  0xc4d23b00,  0xf8142e00,  
            0x2b620100,  0xc29a6c00,  0xc8c3d300,  0x15622500,  
            0x92e34b00,  0xa0d76900,  0x6214f800,  0xb3d37d00,  
            0xb3732300,  0x8d247900,  0x9058e500,  0x4e8f0e00,  
            0x46294800,  0xf4132800,  0x71818600,  0x03f53500,  
    };


    uint32_t expected_horizontal[20] = {
        0x9da5aa00, 0xaab48500, 0xe2706200, 0xde733400, 
        0x767e3600, 0x91956a00, 0x8a957600, 0x6e927c00,
        0x99dd5a00, 0x869a8e00, 0x91949f00, 0x8a73ba00, 
        0xa04b4e00, 0x9a4f8000, 0x79597900, 0x6f737900, 
        0x9d1e3800, 0x8e3f5200, 0x78834b00, 0x3abb5d00,
    };

    uint32_t result_horizontal[width * height] = {0};
    horizontal_blur(TESTDATA_HORIZONTAL, result_horizontal, width, height);

    for(int y=0; y<height; ++y)
    {
        for(int x=0; x<width; ++x)
        {
            int index = y * width + x;
            assert(expected_horizontal[index] == result_horizontal[index]);
        }
    }

    // Transpose the test data, then can use it to test vertical blur.
    uint32_t expected_vertical[width*height] = {};
    uint32_t result_vertical[width*height] = {};
    uint32_t TESTDATA_VERTICAL[width*height] = {};

    transpose(TESTDATA_HORIZONTAL, TESTDATA_VERTICAL, width, height);
    transpose(expected_horizontal, expected_vertical, width, height);

    int newwidth = height;
    int newheight = width;
    vertical_blur(TESTDATA_VERTICAL, result_vertical, newwidth, newheight);

    for(int y=0; y<newheight; ++y)
    {
        for(int x=0; x<newwidth; ++x)
        {
            int index = y * width + x;

            assert(expected_vertical[index] == result_vertical[index]);
        }
    }

    printf("Blur test completed.\n");
}

void graphics_blur(graphics_t *g)
{
    horizontal_blur(g->buffer, g->back_buffer, g->width, g->height);
    vertical_blur(g->back_buffer, g->buffer, g->width, g->height);
}

void graphics_set_pixel(graphics_t *g, int x, int y, uint32_t color)
{
    if(x < 0 || x >= g->width || y < 0 || y >= g->height)
        return;

    x = (x % g->width + g->width) % g->width;
    y = (y % g->height + g->height) % g->height;
    g->buffer[y * g->width + x] = color;
}

void graphics_update(graphics_t *g)
{
    uint32_t *buffer;

    SDL_LockSurface(g->pixels);
    puts("d1");
    memcpy(g->pixels, g->buffer, g->n_buffer_bytes);
    puts("d2");
    puts("d3");
    SDL_BlitSurface(g->pixels, NULL, g->screen, NULL);
    puts("d4");
    puts(SDL_GetError());
    SDL_UpdateWindowSurface(g->window);
    puts(SDL_GetError());
    puts("d5");
    SDL_UnlockSurface(g->pixels);
}

bool graphics_process_events()
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) 
    {
        if (event.type == SDL_EVENT_QUIT) 
        {
            return false;
        }
    }

    return true;
}

void graphics_dispose(graphics_t *g)
{
    if(g == NULL)
    {
        SDL_Quit();
        return;
    }

    puts("Hello1");

    if(g->window)
        SDL_DestroyWindow(g->window);

    if(g->pixels)
        SDL_DestroySurface(g->pixels);

    if(g->screen)
        SDL_DestroySurface(g->screen);

    SDL_Quit();

    free(g->buffer);
    free(g->back_buffer);
    free(g);
}