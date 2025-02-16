#include <stdio.h>

int main() 
{
    int value = 123;
    int *p1 = &value;
    void *void_ptr = p1;
    int *p2 = void_ptr;

    printf("%d\n", *p2);
}