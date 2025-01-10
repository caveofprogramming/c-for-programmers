#include <stdio.h>

struct Item
{
    int id;
    int count;
};

void modify_item(struct Item *pitem)
{
    pitem->id = 123;
    pitem->count = 456;
}

int main() 
{
    struct Item item;
    modify_item(&item);
    printf("item: %d, %d\n", item.id, item.count);
}
