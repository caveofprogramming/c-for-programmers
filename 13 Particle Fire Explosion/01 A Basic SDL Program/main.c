#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    /*
     * Initialize SDL.
     */

    const char title[] = "SDL Test";
    const int width = 800;
    const int height = 600;

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) == false) {
		fprintf(stderr, "Unable to initialize video: %s\n", SDL_GetError());
		return 1;
	}

	SDL_Window *window = SDL_CreateWindow(title, width, height, 0);

	if (window == NULL) 
	{
		fprintf(stderr, "Unable to create window: %s\n", SDL_GetError());
		return 1;
	}

    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);

    if (renderer == NULL) 
	{
		fprintf(stderr, "Unable to create renderer: %s\n", SDL_GetError());
		return 1;
	}

    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, width, height);

    if (texture == NULL) 
	{
		fprintf(stderr, "Unable to create texture: %s\n", SDL_GetError());
		return 1;
	}

    /*
     * Draw on the screen.
     */
    uint32_t *buffer = malloc(width*height*4);
    
    if(buffer == NULL)
    {
        fprintf(stderr, "Unable to allocate buffer.\n");
        return 1;
    }

    for(int i=0; i<width*height; ++i)
    {
        buffer[i] = 0xFF00FF00;
    }

    

    /*
     * Event loop
     */

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

        if(SDL_UpdateTexture(texture, 
            NULL, 
            buffer, 
            width * 4) == false)
        {
            printf("%s\n", SDL_GetError());
            return 0;
        }
    
        SDL_RenderClear(renderer);
        SDL_RenderTexture(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);

        SDL_Delay(2);
    }

    /*
     * Clean up.
     */
    free(buffer);
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}