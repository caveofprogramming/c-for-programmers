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
    /*
     * Add code here so that we return the correct
     * RGB color.
     * 
     * If needed use the macros in graphics.h.
     * 
     * hue, sat and light all range from 0-1.
     * The RGB colour should be equivalent to a 6-digit hex number.
     * E.g if red = 0x12, green = 0xAB and blue = 0x9F, return
     * 0x0012AB9F
     */
    return 0;
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
