#include <stdlib.h>
#include <stdlib.h>
#include "include/particle.h"

void particle_init(particle_t *p)
{
    // Particle is confined to box with centre 0,0
    // and sides of 1 unit.
    p->x = (double)rand()/RAND_MAX - 0.5;
    p->y = (double)rand()/RAND_MAX - 0.5;
}
