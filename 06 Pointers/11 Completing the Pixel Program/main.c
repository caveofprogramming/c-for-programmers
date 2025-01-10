#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "main.h"

int main()
{
    const int NPIXELS = 3; //1280 * 720;
    int nbytes = NPIXELS * sizeof(pixel_t);

    pixel_t * const pixels = (pixel_t *)malloc(nbytes);

    if(!pixels)
    {
        return 1;
    }

    pixel_t * const end = pixels + NPIXELS;

    srand(time(NULL));   

    pixel_t *p = pixels;
    while(p != end)
    {
        p->x = (float)rand()/RAND_MAX; 
        p->y = (float)rand()/RAND_MAX; 
        p->color = (unsigned char)(256 * (rand()/(RAND_MAX + 1.0))); 
        ++p;
    }

    p = pixels;
    while(p != end)
    {
        printf("(%f,%f): %d\n", p->x, p->y, p->color);
        ++p;
    }

    free(pixels);
    return 0;
}