#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdbool.h>

int main() 
{
    /*
     * Initialize SDL.
     */

    const char title[] = "SDL Test";
    const int width = 800;
    const int height = 600;

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) == false) {
		fprintf(stderr, "Unable to initialize video: %s", SDL_GetError());
		return 1;
	}

	SDL_Window *window = SDL_CreateWindow(title, width, height, 0);

	if (window == NULL) 
	{
		fprintf(stderr, "Unable to create window: %s", SDL_GetError());
		return 1;
	}

    SDL_Surface *screen = SDL_GetWindowSurface(window);

    if (screen == NULL) 
	{
		fprintf(stderr, "Unable to create screen surface: %s", SDL_GetError());
		return 1;
	}

    SDL_Surface *pixels = SDL_CreateSurface(width, height, SDL_PIXELFORMAT_RGBX32);

    if (pixels == NULL) 
	{
		fprintf(stderr, "Unable to create pixel surface: %s", SDL_GetError());
		return 1;
	}

    /*
     * Draw on the screen.
     */
    SDL_FillSurfaceRect(pixels, NULL, 0);

    if(SDL_LockSurface(pixels) == false)
    {
        fprintf(stderr, "Unable to lock surface: %s", SDL_GetError());
        return 1;
    }

    //memset(pixels->pixels, 0, width*height*4);

    //SDL_BlitSurface(pixels, NULL, screen, NULL);

    if(SDL_UpdateWindowSurface(window) == false)
    {
        fprintf(stderr, "Unable to update window: %s", SDL_GetError());
    }

    SDL_UnlockSurface(pixels);
    
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
    }

    /*
     * Clean up.
     */

    SDL_DestroySurface(pixels);
    SDL_DestroySurface(screen);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}