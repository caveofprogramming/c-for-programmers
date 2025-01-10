#include <stdio.h>
#include "includes/data.h"

struct Item struct_munger(struct Item item)
{
    item.id = 7;
    item.v[0] = 1;
    item.v[1] = 2;

    return item;
}

int main() 
{ 
    struct Item item = {6, {7, 8}};
    printf("item: %d, {%d, %d}\n", item.id, item.v[0], item.v[1]);

    struct Item result = struct_munger(item);

    printf("item: %d, {%d, %d}\n", item.id, item.v[0], item.v[1]);
    printf("Result: %d, {%d, %d}\n", result.id, result.v[0], result.v[1]);

    return 0;
}