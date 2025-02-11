#include <stdio.h>

//#define POLITE

int main()
{
    #ifdef POLITE
    printf("Please leave me alone.");
    #elif RUDE
    printf("Go!!!");
    #else
    printf("Get lost!");
    #endif

    return 0;
}