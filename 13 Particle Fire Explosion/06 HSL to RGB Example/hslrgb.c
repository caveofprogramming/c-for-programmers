#include "include/hslrgb.h"

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>


double TESTDATA[][6] = 
{   // rgb hsl
    { 0,0,0,0.0000,0.0000,0.0000 },
    { 18,46,23,0.3600,0.4319,0.1260 },
    { 255,255,255,1.0000,1.0000,1.0000 },
    { 223,25,77,0.9561,0.7999,0.4860 },
    { 2,59,15,0.3707,0.9296,0.1198 },
    { 234,123,90,0.0375,0.7773,0.6367 },
    { 205,225,141,0.2061,0.5860,0.7182 },
    { 1,1,2,0.7294,0.5446,0.0060 },
    { 185,252,245,0.4830,0.9053,0.8559 },
    { 15,78,33,0.3814,0.6839,0.1806 },
    { 208,193,254,0.7083,0.9672,0.8768 },
    { 243,221,191,0.0962,0.6915,0.8511 },
    { 184,180,253,0.6737,0.9524,0.8503 },
    { 4,2,4,0.8359,0.4667,0.0111 },
    { 217,179,237,0.7784,0.6101,0.8141 },
    { 29,2,53,0.7533,0.9187,0.1091 },
    { 29,16,17,0.9772,0.2940,0.0872 },
    { 168,34,184,0.8158,0.6846,0.4272 },
    { 231,175,169,0.0159,0.5560,0.7842 },
    { 18,229,206,0.4821,0.8541,0.4834 },
};

uint32_t hsl_to_rgb(double hue, double sat, double light)
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

    double red=0, green=0, blue=0;
    
    if(hue < 1.0)
    {
        red = chroma;
        green = x;
        blue = 0;
    }
    else if(hue < 2.0)
    {
        red = x;
        green = chroma; 
        blue = 0;
    }
    else if(hue < 3.0)
    {
        red = 0;
        green = chroma;
        blue = x;
    }
    else if(hue < 4.0)
    {
        red = 0;
        green = x;
        blue = chroma;
    }
    else if(hue < 5.0)
    {
        red = x;
        green = 0;
        blue = chroma;
    }
    else 
    {
        red = chroma;
        green = 0;
        blue = x;
    }

    double m = light - chroma/2; 
    if(m < 0) m = 0; // m can end up a very tiny -ve number.

    red += m;
    green += m;
    blue += m;

    assert(red >=0 && red <= 1.0);
    assert(green >=0 && green <= 1.0);
    assert(blue >=0 && blue <= 1.0);

    uint32_t r = (uint32_t)round(red * 0xFF);
    uint32_t g = (uint32_t)round(green * 0xFF);
    uint32_t b = (uint32_t)round(blue * 0xFF);

    return RGB(r,g,b);
}

void hsl_test()
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
        
        uint32_t color = hsl_to_rgb(hue, sat, light);

        assert(RED(color) == (int)red);
        assert(GREEN(color) == (int)green);
        assert(BLUE(color) == (int)blue);
    }
}
