#include <stdio.h>

int main() 
{
    int value = 7;

    int *pvalue = &value;

    printf("pointer: %p\n", pvalue);

    *pvalue = 8;

    printf("value: %d\n", value);
}