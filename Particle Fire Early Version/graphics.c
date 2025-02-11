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

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		dprint("Unable to initialise video.");
		return NULL;
	}

	g->window = SDL_CreateWindow(
        title,
	    SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED, 
        width,
		height, 
        SDL_WINDOW_SHOWN);

	if (g->window == NULL) 
	{
		dprint("Cannot create window.");
		return NULL;
	}

	g->renderer = SDL_CreateRenderer(g->window, -1, SDL_RENDERER_PRESENTVSYNC);

    if (g->renderer == NULL) 
	{
		dprint("Unable to initialise renderer.");
		return NULL;
	}

	g->texture = SDL_CreateTexture(g->renderer, 
        SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_STATIC, 
        width, 
        height);

	if (g->texture == NULL) 
	{
		dprint("Unable to create texture.");
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

static uint32_t get_blurred_pixel(graphics_t *graphics, int x, int y)
{
    double red = 0.0;
    double green = 0.0;
    double blue = 0.0;

    for(int row=-1; row <= 1; ++row)
    {
        for(int col=-1; col <= 1; ++col)
        {
            uint32_t color = graphics_get_pixel(graphics, x + row, y + col);
            red += (color & 0xFF000000) >> 24;
            green += (color & 0x00FF0000) >> 16;
            blue += (color & 0x0000FF00) >> 8;
        }
    }

    const double npixels = 9;

    uint32_t r = (uint32_t)round(red/npixels);
    uint32_t g = (uint32_t)round(green/npixels);
    uint32_t b = (uint32_t)round(blue/npixels);

    return (r << 24) + (g << 16) + (b << 8);
}

void graphics_blur(graphics_t *g)
{

    for(int y=0; y<g->height; ++y)
    {
        for(int x=0; x<g->width; ++x)
        {
            uint32_t color = get_blurred_pixel(g, x, y);
            g->back_buffer[y * g->width + x] = color;
        }
    }
    
    memcpy(g->buffer, g->back_buffer, g->width * g->height * 4);
}

uint32_t graphics_get_pixel(graphics_t *g, int x, int y)
{
    x = (x % g->width + g->width) % g->width;
    y = (y % g->height + g->height) % g->height;
    return g->buffer[y * g->width + x];
}

void graphics_set_pixel(graphics_t *g, int x, int y, uint32_t color)
{
    x = (x % g->width + g->width) % g->width;
    y = (y % g->height + g->height) % g->height;
    g->buffer[y * g->width + x] = color;
}

void graphics_update(graphics_t *g)
{
    uint32_t *buffer;
    int *pitch;

    SDL_UpdateTexture(g->texture, 
        NULL, 
        g->buffer, 
        g->width * sizeof(Uint32));

	SDL_RenderClear(g->renderer);
	SDL_RenderCopy(g->renderer, g->texture, NULL, NULL);
	SDL_RenderPresent(g->renderer);
}

bool graphics_process_events()
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) 
    {
        if (event.type == SDL_QUIT) 
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

    free(g->buffer);
    free(g->back_buffer);

    if(g->texture)
        SDL_DestroyTexture(g->texture);

    if(g->renderer)
        SDL_DestroyRenderer(g->renderer);

    if(g->window)
        SDL_DestroyWindow(g->window);

    SDL_Quit();

    free(g);
}