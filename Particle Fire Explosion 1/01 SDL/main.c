#include "include/graphics.h"

int main()
{
    graphics_t *graphics = graphics_init("Particle Fire", 1000, 1000);

    while(graphics_process_events());

    graphics_dispose(graphics);
    return 0;
}