#include <stdio.h>

int main()
{
    int value = 0;
    printf("value: %d\n", value++);
    printf("value: %d\n", value);

    printf("\n");

    value = 0;
    printf("value: %d\n", ++value);
    printf("value: %d\n", value);

    printf("\n");
    
    value = 1;
    printf("Result: %d\n", 2 * value++ + ++value);
}
