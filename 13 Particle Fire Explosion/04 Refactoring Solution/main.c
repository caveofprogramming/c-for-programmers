#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "include/graphics.h"

/*
 * Present a window filled with green.
 */

int main(int argc, char** argv)
{
    const int width = 800;
    const int height = 600;

    gs_graphics *g = gs_init_graphics("Particle Fire", width, height);

    for(int i=0; i<width*height; ++i)
    {
        g->buffer[i] = 0xFF00FF00;
    }

    gs_event_loop(g);
    gs_dispose_graphics(g);
    return 0;
}