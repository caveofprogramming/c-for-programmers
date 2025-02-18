#include <stdlib.h>
#include <math.h>
#include "include/particle.h"

void particle_init(particle_t *p)
{
    p->x = 0;
    p->y = 0;
    p->angular_speed = 0.0003 * rand()/RAND_MAX;
    p->speed = rand()*0.0001/RAND_MAX + 0.00001;
    //p->speed = rand()*0.00001/RAND_MAX + 0.00001;
    //p->speed = rand()*0.0000001/RAND_MAX + 0.00001;
    p->direction = (2.0 * PI * rand())/RAND_MAX;
}

void particle_update(particle_t *p, int elapsed)
{
    p->x += elapsed * p->speed * cos(p->direction);
    p->y += elapsed * p->speed * sin(p->direction);
    p->direction += elapsed * p->angular_speed;
}