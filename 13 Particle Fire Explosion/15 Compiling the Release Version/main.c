#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "include/graphics.h"
#include "include/swarm.h"

/*
 *
 */

int main(int argc, char** argv)
{
    const int width = 800;
    const int height = 600;
    const int nparticles = 2000;

    gs_graphics *g = gs_init_graphics("Particle Fire", width, height);
    particle_t *swarm = swarm_create(nparticles);
    
    
    while(gs_poll_events(g))
    {
        swarm_update(swarm, nparticles);
        swarm_draw(swarm, g, nparticles);
        graphics_blur(g);
        gs_draw(g);
    }


    gs_dispose_graphics(g);
    swarm_dispose(swarm);
    return 0;
}