#include <stdio.h>
#include "color.h"

uint32_t color_to_int(char red, char green, char blue)
{
    color_t c;
    c.colors[0] = blue;
    c.colors[1] = green;
    c.colors[2] = red;
    c.colors[3] = 0;
    return c.color;
}
void int_to_color(uint32_t color_value, char *red, char *green, char *blue)
{
    color_t c;
    c.color = color_value;
    *blue = c.colors[0];
    *green = c.colors[1];
    *red = c.colors[2];
}
