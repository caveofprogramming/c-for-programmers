#include <stdio.h>

int main() 
{
    struct Item
    {
        int id;
        int count;
    } item1;

    struct Item *pitem = &item1;

    (*pitem).id = 123;
    pitem->count = 456;

    printf("item1: %d, %d\n", item1.id, item1.count);
}
