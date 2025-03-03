#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "include/graphics.h"
#include "include/swarm.h"

/*
 * Implemented the blur functions.
 * 
 * Next: tweak the particle motion and colour change in whatever way seems good.
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