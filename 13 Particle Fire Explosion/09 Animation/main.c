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
 * - Moved swarm_draw inside the event loop
 *
 * Next:
 * Initialise the particles so that they start at the centre of the screen and have random
 * speed, angular speed and direction.
 * 
 * Add a particle_update function that updates the particle's position based on its speed, 
 * angular speed, direction and elapsed time.
 * 
 * Direction should range from 0 to 2 x PI. Use trig functions to calculate x and y speed
 * based on these values -- or alternatively, scrap that and just try to do something that
 * looks interesting.
 * 
 * Add a swarm_update function that calls particle_update for all the particles and call it
 * in the event loop in main().
 * 
 * Make hue static and increment it during each call to swarm_draw, to gradually change the color.
 * May need to reset hue to 0 if it becomes greater than 1.
 */

int main(int argc, char** argv)
{
    const int width = 800;
    const int height = 600;
    const int nparticles = 1000;

    gs_graphics *g = gs_init_graphics("Particle Fire", width, height);
    particle_t *swarm = swarm_create(nparticles);

    
    while(gs_poll_events(g))
    {
        swarm_draw(swarm, g, nparticles);
        gs_draw(g);
    }

    gs_dispose_graphics(g);
    swarm_dispose(swarm);
    return 0;
}