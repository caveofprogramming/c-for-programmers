#include <stdlib.h>
#include <stdbool.h>
#include "include/graphics.h"

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

    g->texture = SDL_CreateTexture(g->renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, width, height);

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

    return g;
}

bool gs_event_loop(gs_graphics *g)
{
    bool running = true;

    while(running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event)) 
        {
            if (event.type == SDL_EVENT_QUIT) 
            {
                running = false;
            }
            else if (event.type == SDL_EVENT_KEY_UP && event.key.key == SDLK_ESCAPE)
            {
                running = false;
            }
        }

        /*
         * Draw on the screen.
         */
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
}
