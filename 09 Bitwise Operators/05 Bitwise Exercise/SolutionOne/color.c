#include <stdio.h>
#include "color.h"

uint32_t color_to_int(char red, char green, char blue)
{
    uint32_t result = red;
    result <<= 8;

    result += green;
    result <<= 8;

    result += blue;

    return result;
}

void int_to_color(uint32_t color_value, char *red, char *green, char *blue)
{
    *red = (char)((color_value & 0x00FF0000) >> 16);
    *green = (char)((color_value & 0x0000FF00) >> 8);
    *blue = (char)(color_value & 0x000000FF);
}
