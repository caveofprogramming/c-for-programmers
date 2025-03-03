#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include "include/graphics.h"


/* 
 * This is just used to transpose the test data so it can be used to test vertical
 * as well as horizontal blur.
 */
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
            0x004fde97,  0x00ec6cbd,  0x00c4d23b,  0x00f8142e,  
            0x002b6201,  0x00c29a6c,  0x00c8c3d3,  0x00156225,  
            0x0092e34b,  0x00a0d769,  0x006214f8,  0x00b3d37d,  
            0x00b37323,  0x008d2479,  0x009058e5,  0x004e8f0e,  
            0x00462948,  0x00f41328,  0x00718186,  0x0003f535,  
    };


    uint32_t expected_horizontal[20] = {
        0x009da5aa, 0x00aab485, 0x00e27062, 0x00de7334, 
        0x00767e36, 0x0091956a, 0x008a9576, 0x006e927c,
        0x0099dd5a, 0x00869a8e, 0x0091949f, 0x008a73ba, 
        0x00a04b4e, 0x009a4f80, 0x00795979, 0x006f7379, 
        0x009d1e38, 0x008e3f52, 0x0078834b, 0x003abb5d,
    };

    const int nbytes = width * height * sizeof(uint32_t);
    uint32_t *expected_vertical = malloc(nbytes);
    uint32_t *result_horizontal = malloc(nbytes);
    uint32_t *result_vertical = malloc(nbytes);
    uint32_t *TESTDATA_VERTICAL = malloc(nbytes);

    memset(expected_vertical, 0, nbytes);
    memset(result_horizontal, 0, nbytes);
    memset(result_vertical, 0, nbytes);
    memset(TESTDATA_VERTICAL, 0, nbytes);

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

    free(expected_vertical);
    free(result_horizontal);
    free(result_vertical);
    free(TESTDATA_VERTICAL);
}


void graphics_blur(gs_graphics *g)
{
    horizontal_blur(g->buffer, g->back_buffer, g->width, g->height);
    vertical_blur(g->back_buffer, g->buffer, g->width, g->height);
}


static void horizontal_blur(uint32_t *input, uint32_t *output, int width, int height)
{
    // Note: read from input and write to output.
}


static void vertical_blur(uint32_t *input, uint32_t *output, int width, int height)
{
   // Note: read from input and write to output.
}

gs_graphics *gs_init_graphics(char title[], int width, int height)
{
    gs_graphics *g = malloc(sizeof(gs_graphics));

    g->width = width;
    g->height = height;

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) == false) {
		fprintf(stderr, "Unable to initialize video: %s\n", SDL_GetError());
		return NULL;
	}

	g->window = SDL_CreateWindow(title, width, height, 0);

	if (g->window == NULL) 
	{
		fprintf(stderr, "Unable to create window: %s\n", SDL_GetError());
		return NULL;
	}

    g->renderer = SDL_CreateRenderer(g->window, NULL);

    if (g->renderer == NULL) 
	{
		fprintf(stderr, "Unable to create renderer: %s\n", SDL_GetError());
		return NULL;
	}

    g->texture = SDL_CreateTexture(g->renderer, SDL_PIXELFORMAT_XRGB8888, SDL_TEXTUREACCESS_STATIC, width, height);

    if (g->texture == NULL) 
	{
		fprintf(stderr, "Unable to create texture: %s\n", SDL_GetError());
		return NULL;
	}

    /*
     * Buffer for drawing pixels.
     */
    g->buffer = malloc(width*height*4);
    
    if(g->buffer == NULL)
    {
        fprintf(stderr, "Unable to allocate buffer.\n");
        return NULL;
    }

    /* Buffer for use with blur algorithm */
    g->back_buffer = malloc(width*height*4);
    
    if(g->back_buffer == NULL)
    {
        fprintf(stderr, "Unable to allocate back buffer.\n");
        return NULL;
    }
    

    return g;
}

bool gs_draw(gs_graphics *g)
{
   /*
    * Draw on the screen.
    */

    static int time = 0;
    g->elapsed = SDL_GetTicks() - time;
    time = SDL_GetTicks();

    if(SDL_UpdateTexture(g->texture, 
        NULL, 
        g->buffer, 
        g->width * 4) == false)
    {
        printf("Error updating texture: %s\n", SDL_GetError());
        return false;
    }

    SDL_RenderClear(g->renderer);
    SDL_RenderTexture(g->renderer, g->texture, NULL, NULL);
    SDL_RenderPresent(g->renderer);

    SDL_Delay(2);
}

bool gs_poll_events(gs_graphics *g)
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) 
    {
        if (event.type == SDL_EVENT_QUIT) 
        {
            return false;
        }
        else if (event.type == SDL_EVENT_KEY_UP && event.key.key == SDLK_ESCAPE)
        {
            return false;
        }
    }

    return true;
}

void gs_dispose_graphics(gs_graphics *g)
{
    /*
     * Clean up.
     */
    SDL_DestroyTexture(g->texture);
    SDL_DestroyRenderer(g->renderer);
    SDL_DestroyWindow(g->window);
    SDL_Quit();
    free(g->buffer);
    free(g->back_buffer);
}
