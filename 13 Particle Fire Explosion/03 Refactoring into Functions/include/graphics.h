#ifndef GRAPHICS_H_INCLUDED_
#define GRAPHICS_H_INCLUDED_

#include <SDL3/SDL.h>

typedef struct 
{
    int width;
    int height;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    uint32_t *buffer;
} gs_graphics;

gs_graphics *gs_init_graphics(char title[], int width, int height);
bool gs_event_loop(gs_graphics *g);
void gs_dispose_graphics(gs_graphics *g);


#endif
