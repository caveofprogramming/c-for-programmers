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
 * Complete the function hslrgb in graphics.c to convert
 * hue, saturation and lightness values to an RGB color value.
 * 
 * The tests run below by hsl_test() should then pass and a rainbow
 * will be displayed.
 * 
 */

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
            // Note: using "|" to add alpha value.
            g->buffer[y * width + x] = 0xFF000000 | hsl_to_rgb((double)y/height, 1, 0.5);
        }
    }
    
    gs_event_loop(g);
    gs_dispose_graphics(g);
    return 0;
}