#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "include/graphics.h"

/*
 * Present a window filled with green.asm
 *
 * Next: refactor this into three functions and a struct.
 * 
 * The struct contains all variables that would otherwise
 * have to be global, including the pixel buffer.
 * It should also store the width and height of the window.
 * 
 * An initialization function creates this struct and returns 
 * it after initializing the SDL graphics.asm
 * 
 * This is paired with a destroy function that frees all
 * objects and quits the program.
 * 
 * In-between, an event loop function checks for events
 * and draws whatever is currently in the pixel buffer.
 * 
 * main() should only call these three functions.
 * 
 * Consider prefixing the functions with a common prefix
 * to ensure they don't conflict with any other function.
 * E.g. gs_
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