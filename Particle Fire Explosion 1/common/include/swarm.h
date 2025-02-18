#ifndef SWARM_H_INCLUDED_
#define SWARM_H_INCLUDED_

#include "graphics.h"
#include "particle.h"

particle_t *swarm_create();
void swarm_draw(particle_t *particles, graphics_t *, int num_particles);
void swarm_update(particle_t *particles, int num_particles, int elapsed);
void swarm_dispose(particle_t *swarm);


#endif