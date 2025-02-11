#include <stdio.h>
#include <stdint.h>
#include <SDL.h>
#include <stdio.h>
#include "include/graphics.h"
#include "include/swarm.h"

int main() 
{
	const int num_particles = 1000;
    graphics_t *g = graphics_init("Particle Fire", 1000, 1000);
	particle_t *particles = swarm_create(num_particles);

	int last_time = SDL_GetTicks();

	while(1)
	{
		int elapsed = SDL_GetTicks() - last_time;
		last_time = SDL_GetTicks();

		swarm_update(particles, num_particles, elapsed);
		swarm_draw(particles, g, num_particles);
		graphics_blur(g);
		graphics_update(g);

		if(!graphics_process_events())
		{
			return 0;
		}

		SDL_Delay(15);
	}

    graphics_dispose(g);
	swarm_dispose(particles);
    return 0;
}