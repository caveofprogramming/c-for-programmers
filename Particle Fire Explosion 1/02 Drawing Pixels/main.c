#include "include/graphics.h"

int main()
{
    graphics_t *g = graphics_init("Particle Fire", 1000, 1000);

    for(int i=0; i<g->width*g->height; ++i)
    {
        g->buffer[i] = 0xFF000000;
    }

    graphics_update(g);

    while(graphics_process_events());

    graphics_dispose(g);
    return 0;
}