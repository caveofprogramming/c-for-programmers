#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "include/graphics.h"
#include "include/swarm.h"

/*
 * Create and draw swarm.
 */

int main(int argc, char** argv)
{
    const int width = 800;
    const int height = 600;
    const int nparticles = 1000;

    gs_graphics *g = gs_init_graphics("Particle Fire", width, height);
    particle_t *swarm = swarm_create(nparticles);

    swarm_draw(swarm, g, nparticles);
    
    gs_event_loop(g);
    gs_dispose_graphics(g);
    swarm_dispose(swarm);
    return 0;
}