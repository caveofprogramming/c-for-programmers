#ifndef PARTICLE_H_INCLUDED_
#define PARTICLE_H_INCLUDED_

#define PI 3.141592

typedef struct 
{
    double x;
    double y;
    double speed;
    double angular_speed;
    double direction;
} particle_t;

void particle_init(particle_t *p);
void particle_update(particle_t *p, int elapsed);

#endif