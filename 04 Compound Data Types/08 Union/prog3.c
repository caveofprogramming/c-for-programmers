#include <stdio.h>

int main()  
{
    union Value
    {
        short value;
        char values[2];
    } v1;

    v1.value = 1;

    printf("size of v1: %lu\n", sizeof(v1));
    
    printf("value: %d\n", v1.value);
    printf("values: %d,%d\n", v1.values[0], v1.values[1]);

    return 0;
}