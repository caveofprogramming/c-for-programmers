#ifndef HSLRGB_H_INCLUDED
#define HSLRGB_H_INCLUDED

#include <stdint.h>
#include "graphics.h"

static uint32_t hsl_to_rgb(double hue, double sat, double l);
void hsl_test();

#endif