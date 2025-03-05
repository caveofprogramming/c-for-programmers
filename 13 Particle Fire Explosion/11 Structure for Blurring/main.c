#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "include/graphics.h"
#include "include/swarm.h"

/*
 * Here I've implemented all the code suggested in the last project.
 * I also changed the scale factor in swarm.c so that both x and y
 * scale the same way, to create a circular explosion.
 * 
 * Added a "back buffer" in graphics.h and graphics.c so that the blur
 * has some memory to work with.
 * 
 * Added graphics_blur(g) in the event loop in main.
 * 
 * Added graphics test code and calling graphics_test_blur() at start of main.
 * 
 * Changed pixel format to SDL_PIXELFORMAT_XRGB8888 (instead of SDL_PIXELFORMAT_XRGB8888)
 * so that we can forget about the alpha value.
 * 
 * TODO:
 * 
 * Implement the horizontal_blur and vertical_blur functions in graphics.c so that
 * the tests pass.
 * 
 * Note: use only integer divsions for the divisions, otherwise the tests won't pass.
 * 
 */

int main(int argc, char** argv)
{
    graphics_test_blur();

    const int width = 800;
    const int height = 600;
    const int nparticles = 1000;

    gs_graphics *g = gs_init_graphics("Particle Fire", width, height);
    particle_t *swarm = swarm_create(nparticles);
    
    
    while(gs_poll_events(g))
    {
        swarm_update(swarm, g, nparticles);
        swarm_draw(swarm, g, nparticles);
        graphics_blur(g);
        gs_draw(g);
    }


    gs_dispose_graphics(g);
    swarm_dispose(swarm);
    return 0;
}