#ifndef HSLRGB_H_INCLUDED
#define HSLRGB_H_INCLUDED

#include <stdint.h>

typedef struct {
    double red;
    double green; 
    double blue;
} rgb_t;

static rgb_t hsl_to_rgb(double hue, double sat, double l);
void test_hslrgb();
static uint32_t tuple_to_bytes(double a, double b, double c, double d);
uint32_t hslrgb(double hue, double sat, double light);

#endif