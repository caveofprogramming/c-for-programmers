#include <stdio.h>

int main()  
{
    union Value
    {
        int value;
        char values[4];
    } v1;

    v1.value = 1;

    printf("size of v1: %lu\n", sizeof(v1));
    
    printf("value: %d\n", v1.value);
    printf("values: %d%d%d%d\n", 
        v1.values[0], 
        v1.values[1],
        v1.values[2],
        v1.values[3]);

    return 0;
}