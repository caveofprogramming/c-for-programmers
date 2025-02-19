#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "include/graphics.h"
#include "include/hslrgb.h"

/*
 * Note: in graphics.h, I've added macros RGB, R, G and B for converting
 * between separate RGB values and a combined RGB value.
 * 
 * E.g. if color = 0x123456, RED(color) is 0x12
 * and RGB(12,34,56) is 0x123456
 * 
 */

int main(int argc, char** argv)
{
    // Call the hsl_to_rgb test function.
    hsl_test();

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