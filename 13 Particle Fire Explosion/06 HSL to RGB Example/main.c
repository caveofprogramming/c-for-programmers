#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "include/graphics.h"
#include "include/hslrgb.h"

int main(int argc, char** argv)
{
    // Call the hsl_to_rgb test function.
    hsl_test();

    const int width = 800;
    const int height = 600;

    gs_graphics *g = gs_init_graphics("Particle Fire", width, height);

    for(int y=0; y<height; ++y)
    {
        for(int x=0; x<width; ++x)
        {
            g->buffer[y * width + x] = 0xFF000000 | hsl_to_rgb((double)y/height, 1, 0.5);
        }
    }
    
    gs_event_loop(g);
    gs_dispose_graphics(g);
    return 0;
}