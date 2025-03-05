#include <stdlib.h>
#include "include/hslrgb.h"
#include "include/swarm.h"

particle_t *swarm_create(int num_particles)
{
    particle_t *p = (particle_t *)malloc(sizeof(particle_t) * num_particles);

    for(int i=0; i<num_particles; ++i)
    {
        particle_init(p + i);
    }

    return p;
}

void swarm_draw(particle_t *particles, gs_graphics *g, int num_particles)
{
    double hue = 0.3;

    for(int i=0; i<num_particles; ++i)
    {
        particle_t *p = particles + i;

        int x = (int)(g->width * p->x) + g->width/2;
        int y = (int)(g->height * p->y) + g->height/2;

        int32_t color = hsl_to_rgb(hue, 1, 0.7);

        if(x >= 0 && y >= 0 && x < g->width && y < g->height)
            g->buffer[y * g->width + x] = color;
    }
}

void swarm_dispose(particle_t *swarm)
{
    free(swarm);
}