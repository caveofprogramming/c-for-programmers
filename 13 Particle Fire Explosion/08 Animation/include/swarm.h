#ifndef SWARM_H_INCLUDED_
#define SWARM_H_INCLUDED_

#include "graphics.h"
#include "particle.h"

particle_t *swarm_create(int num_particles);
void swarm_draw(particle_t *particles, gs_graphics *, int num_particles);
void swarm_dispose(particle_t *swarm);

#endif