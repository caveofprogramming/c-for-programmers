#include "include/graphics.h"
#include <assert.h>

#define DEBUG

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