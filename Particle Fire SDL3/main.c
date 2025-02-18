#include <stdio.h>
#include <stdint.h>
#include <SDL3/SDL.h>
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

	puts("Hello2");

	while(1)
	{
		int elapsed = SDL_GetTicks() - last_time;
		last_time = SDL_GetTicks();

		puts("Hello4");

		swarm_update(particles, num_particles, elapsed);
		swarm_draw(particles, g, num_particles);

		puts("Hello5");
		graphics_blur(g);
		puts("Hello6");
		graphics_update(g);
		puts("Hello7");


		if(!graphics_process_events())
		{
			puts("Hello7");
			return 0;
		}

		SDL_Delay(15);
	}

	puts("Hello3");

    graphics_dispose(g);
	swarm_dispose(particles);
    return 0;
}