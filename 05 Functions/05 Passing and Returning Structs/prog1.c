#include <stdio.h>
#include "includes/data.h"

int main() 
{ 
    struct Item item1 = {1, {2, 3}};
    printf("item1: %d, {%d, %d}\n", item1.id, item1.v[0], item1.v[1]);

    struct Item item2 = item1;
    item1.v[0] = 100;
    printf("item2: %d, {%d, %d}\n", item2.id, item2.v[0], item2.v[1]);

    return 0;
}