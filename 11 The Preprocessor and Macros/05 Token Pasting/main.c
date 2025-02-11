#include <stdio.h>

#define VAR(var, n) var ## n

int main()
{
    int value1 = 7;

    printf("%d\n", VAR(value, 1));
    return 0;
}