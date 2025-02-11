#pragma once

#include <stdint.h>

uint32_t color_to_int(char red, char green, char blue);
void int_to_color(uint32_t color_value, char *red, char *green, char *blue);
