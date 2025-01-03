#include <stdio.h>

int main()  
{
    int numbers[3];

    numbers[0] = 6;
    numbers[1] = 5;
    numbers[2] = 5;

    int values[] = {5, 6, 7, 8};

    printf("Size of array: %lu\n\n", sizeof(values));

    for(int i=0; i < sizeof(values)/sizeof(int); ++i)
    {
        printf("At index %d: %d\n", i, values[i]);
    }
}