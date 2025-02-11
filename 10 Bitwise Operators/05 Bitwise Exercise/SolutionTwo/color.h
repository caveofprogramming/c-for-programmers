#pragma once

#include <stdint.h>

typedef union Color
{
    char colors[4];
    uint32_t color;
} color_t;

uint32_t color_to_int(char red, char green, char blue);
void int_to_color(uint32_t color_value, char *red, char *green, char *blue);
