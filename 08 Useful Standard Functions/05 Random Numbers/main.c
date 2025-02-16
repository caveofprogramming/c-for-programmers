#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <limits.h>

int main()
{
    srand(time(NULL));

    printf("%d\n", rand());
    printf("%d\n", rand());
    printf("%d\n", rand());
    printf("\n");
    printf("%x\n", RAND_MAX);
    printf("%x\n", INT_MAX);
    printf("\n");

    for(int i=0; i<400; ++i)
    {
        if(i % 20 == 0)
            printf("\n");

        unsigned char color = (unsigned char)(0x100 * (double)rand()/(RAND_MAX - 1));
        printf("%02x ", color);
    }

}