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

#define RED(color) ((color >> 16) & 0xFF)
#define GREEN(color) ((color >> 8) & 0xFF)
#define BLUE(color) (color & 0xFF)
#define RGB(r, g, b) ((r << 16) | (g << 8) | b)

gs_graphics *gs_init_graphics(char title[], int width, int height);
bool gs_poll_events(gs_graphics *g);
void gs_dispose_graphics(gs_graphics *g);


#endif
