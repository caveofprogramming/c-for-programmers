#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "include/graphics.h"
#include "include/swarm.h"

/*
 * - Changed particle struct to add new fields.
 * - Separated gs_event_loop into two separate functions, gs_draw and gs_poll_events.
 * - Removed the while loop from gs_poll_events and put it below.
 * - Added code into gs_draw which sets a new 'elapsed' field in the graphics struct
 *   to the number of milliseconds that have passed since the last draw.
 * 
 * Next:
 * Initialise the particles so that they start at the centre of the screen and have random
 * speed, angular speed and direction.
 * 
 * Add a particle_update function that updates the particle's position based on its speed, 
 * angular speed, direction and elapsed time.
 * 
 * Add a swarm_update function that calls particle_update for all the particles and call it
 * in the event loop in main().
 */

int main(int argc, char** argv)
{
    const int width = 800;
    const int height = 600;
    const int nparticles = 1000;

    gs_graphics *g = gs_init_graphics("Particle Fire", width, height);
    particle_t *swarm = swarm_create(nparticles);

    swarm_draw(swarm, g, nparticles);
    
    while(gs_poll_events(g))
    {
        gs_draw(g);
    }

    gs_dispose_graphics(g);
    swarm_dispose(swarm);
    return 0;
}