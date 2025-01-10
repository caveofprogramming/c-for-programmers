#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "main.h"

int main()
{
    const int NPIXELS = 1280 * 720;
    int nbytes = NPIXELS * sizeof(pixel_t);

    printf("float size: %lu bytes\n", sizeof(float));
    printf("pixel_t size: %lu bytes\n", sizeof(pixel_t));
    printf("need %d bytes\n", nbytes);

    pixel_t * const pixels = (pixel_t *)malloc(nbytes);

    if(!pixels)
    {
        printf("Allocation failed.");
        return 1;
    }

    free(pixels);
    return 0;
}