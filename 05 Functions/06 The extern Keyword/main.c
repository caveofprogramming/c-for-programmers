#include <stdio.h>
#include "includes/data.h"

int main() 
{
    printf("count 1: %d\n", count);
    inc_count();
    printf("count 2: %d\n", count);
    return 0;
}