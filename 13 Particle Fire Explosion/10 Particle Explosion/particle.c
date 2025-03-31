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
    p->speed = 0.0005 * rand() / RAND_MAX;
    p->angular_speed = 0.005 * rand() / RAND_MAX;
    p->direction = 2 * PI * rand() / RAND_MAX;
}

void particle_update(particle_t *p)
{
    p->x += cos(p->direction) * p->speed;
    p->y += sin(p->direction) * p->speed;

    p->direction += p->angular_speed;
}
