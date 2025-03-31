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
    uint32_t *back_buffer;
} gs_graphics;

#define RED(color) ((color >> 16) & 0xFF)
#define GREEN(color) ((color >> 8) & 0xFF)
#define BLUE(color) (color & 0xFF)
#define RGB(r, g, b) ((r << 16) | (g << 8) | b)

void graphics_blur(gs_graphics *g);
void graphics_test_blur();
static void horizontal_blur(uint32_t *input, uint32_t *output, int width, int height);
static void vertical_blur(uint32_t *input, uint32_t *output, int width, int height);

gs_graphics *gs_init_graphics(char title[], int width, int height);
bool gs_poll_events(gs_graphics *g);
bool gs_draw(gs_graphics *g);
void gs_dispose_graphics(gs_graphics *g);


#endif
