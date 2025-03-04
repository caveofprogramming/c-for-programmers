#include <stdlib.h>
#include <stdlib.h>
#include <math.h>
#include "include/particle.h"

#define PI 3.141592

void particle_init(particle_t *p)
{
    // Particle is confined to box with centre 0,0
    // and sides of 1 unit.
    p->x = 0;
    p->y = 0;

    double rnd = 0.0001 + 0.00004 * rand() / RAND_MAX;
    p->speed = rnd;

    //p->speed = 0.0001 + 0.00006 * rand() / RAND_MAX;
    p->angular_speed = 0.06 * rand() / RAND_MAX;
    p->direction = 2 * PI * rand() / RAND_MAX;
}

void particle_update(particle_t *p, int elapsed)
{
    p->x += cos(p->direction) * elapsed * p->speed;
    p->y += sin(p->direction) * elapsed * p->speed;

    if(p->x*p->x + p->y*p->y > 1)
    {
        p->x = 0;
        p->y = 0;
    }

    p->direction += p->angular_speed;
}
