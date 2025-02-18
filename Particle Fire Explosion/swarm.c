#include <stdlib.h>
#include "include/swarm.h"
#include "include/hslrgb.h"

particle_t *swarm_create(int num_particles)
{
    particle_t *p = (particle_t *)malloc(sizeof(particle_t) * num_particles);

    for(int i=0; i<num_particles; ++i)
    {
        particle_init(p + i);
    }

    return p;
}

void swarm_update(particle_t *particles, int num_particles, int elapsed)
{
    for(int i=0; i<num_particles; ++i)
    {
        particle_t *p = particles + i;
        particle_update(p, elapsed);
    }
}

void swarm_draw(particle_t *particles, graphics_t *g, int num_particles)
{
    static double hue = 0;

    hue += 0.001;

    for(int i=0; i<num_particles; ++i)
    {
        particle_t *p = particles + i;

        if(p->x * p->x + p->y * p->y > 1)
        {
            particle_init(p);
        }

        int x = (int)(g->width * p->x) + g->width/2;
        int y = (int)(g->height * p->y) + g->height/2;

        int32_t color = hslrgb(hue, 1, 0.7);
        graphics_set_pixel(g, x, y, color);
    }
}

void swarm_dispose(particle_t *swarm)
{
    free(swarm);
}