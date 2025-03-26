#ifndef PARTICLE_H_INCLUDED_
#define PARTICLE_H_INCLUDED_

typedef struct 
{
    double x;
    double y;
} particle_t;

void particle_init(particle_t *p);

#endif