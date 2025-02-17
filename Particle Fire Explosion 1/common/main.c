#include <stdio.h>
#include <stdint.h>
#include <SDL.h>
#include <stdio.h>
#include "include/graphics.h"
#include "include/swarm.h"

void average(uint32_t c1, uint32_t c2, uint32_t c3)
{
	int red = RED(c1) + RED(c2) + RED(c3);;
	int green = GREEN(c1) + GREEN(c2) + GREEN(c3);
	int blue = BLUE(c1) + BLUE(c2) + BLUE(c3);;

	int count = c3 < 0.1? 2: 3;

	uint32_t c = RGB(red/count, green/count, blue/count);
	printf("\nRESULT: %08x\n", c);
}

int main() 
{
	graphics_test_blur();

	const int num_particles = 4000;
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