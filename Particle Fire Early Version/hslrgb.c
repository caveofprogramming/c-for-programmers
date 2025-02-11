#include "include/hslrgb.h"

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

double TESTDATA[][6] = 
{   // rgb hsl
    { 0.0000,0.0000,0.0000,0.0000,0.0000,0.0000 },
    { 0.0760,0.0774,0.0729,0.2191,0.0298,0.0751 },
    { 1.0000,1.0000,1.0000,1.0000,1.0000,1.0000 },
    { 0.0748,0.0061,0.0637,0.8601,0.8501,0.0404 },
    { 0.0488,0.2559,0.2811,0.5180,0.7039,0.1650 },
    { 0.1390,0.0201,0.1536,0.8151,0.7684,0.0868 },
    { 0.0241,0.0488,0.0417,0.4518,0.3386,0.0365 },
    { 0.5211,0.3066,0.5440,0.8173,0.2790,0.4253 },
    { 0.2436,0.4741,0.2806,0.3600,0.3211,0.3589 },
    { 0.5996,0.2898,0.2188,0.0311,0.4653,0.4092 },
    { 0.7348,0.7444,0.7971,0.6410,0.1329,0.7659 },
    { 0.9745,0.8729,0.7954,0.0722,0.7785,0.8849 },
    { 0.1030,0.1047,0.1034,0.3753,0.0082,0.1038 },
    { 0.4618,0.4300,0.3090,0.1320,0.1981,0.3854 },
    { 0.7205,0.5208,0.9366,0.7467,0.7662,0.7287 },
    { 0.1409,0.9096,0.5670,0.4257,0.8096,0.5252 },
    { 0.2652,0.2960,0.2922,0.4794,0.0548,0.2806 },
    { 0.4833,0.0477,0.7709,0.7671,0.8835,0.4093 },
    { 0.1099,0.1450,0.1343,0.4494,0.1374,0.1274 },
    { 0.6982,0.3060,0.8209,0.7936,0.5898,0.5635 },
};

uint32_t hslrgb(double hue, double sat, double light)
{
    rgb_t rgb = hsl_to_rgb(hue, sat, light);
    return tuple_to_bytes(rgb.red, rgb.green, rgb.blue, 0);
}


rgb_t hsl_to_rgb(double hue, double sat, double light)
{
    assert(hue >= 0);
    assert(sat >= 0 && sat <= 1.0);
    assert(light >= 0 && light <= 1.0);

    hue = (hue - floor(hue)) * 6.0;
    assert(hue >=0 && hue <= 6.0);

    double chroma = (1 - fabs(2*light - 1)) * sat;

    double hue_mod_2 = hue - (((int)hue/2) * 2);
    assert(hue_mod_2 < 2.0);

    double x = chroma * (1 - fabs(hue_mod_2 - 1));

    rgb_t rgb;
    
    if(hue < 1.0)
    {
        rgb = (rgb_t) { .red = chroma, .green = x, .blue = 0 };
    }
    else if(hue < 2.0)
    {
        rgb = (rgb_t) { .red = x, .green = chroma, .blue = 0 };
    }
    else if(hue < 3.0)
    {
        rgb = (rgb_t) { .red = 0, .green = chroma, .blue = x };
    }
    else if(hue < 4.0)
    {
        rgb = (rgb_t) { .red = 0, .green = x, .blue = chroma };
    }
    else if(hue < 5.0)
    {
        rgb = (rgb_t) { .red = x, .green = 0, .blue = chroma };
    }
    else 
    {
        rgb = (rgb_t) { .red = chroma, .green = 0, .blue = x };
    }

    assert(hue >= 0 && hue <= 6.0);

    double m = light - chroma/2; 
    if(m < 0) m = 0; // m can end up a very tiny -ve number.

    rgb.red += m;
    rgb.green += m;
    rgb.blue += m;

    assert(rgb.red >=0 && rgb.red <= 1.0);
    assert(rgb.green >=0 && rgb.green <= 1.0);
    assert(rgb.blue >=0 && rgb.blue <= 1.0);

    return rgb;
}

static bool close(double a, double b)
{
    return fabs(a-b) < 0.001;
}

static uint32_t tuple_to_bytes(double a, double b, double c, double d)
{
    uint32_t result = 0;

    result += ((uint32_t)round(a * 0xFF)) << 24;
    result += ((uint32_t)round(b * 0xFF)) << 16;
    result += ((uint32_t)round(c * 0xFF)) << 8;
    result += ((uint32_t)round(d * 0xFF));

    return result;
}

void test_hslrgb()
{
    const int rowsize = sizeof(double) * 6;
    double entries = sizeof(TESTDATA)/rowsize;

    double *p = (double *)TESTDATA;
    
    for(int i=0; i<entries; ++i)
    {
        double red = *p++;
        double green = *p++;
        double blue = *p++;
        double hue = *p++;
        double sat = *p++;
        double light = *p++;
        
        rgb_t result = hsl_to_rgb(hue, sat, light);

        assert(close(result.red, red));
        assert(close(result.green, green));
        assert(close(result.blue, blue));
    }
}
