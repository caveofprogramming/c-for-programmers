#include <stdio.h>

const int N1 = 1;
const int N2 = 2;

void modify_pointer(const int **p)
{
    *p =  &N2;
}

int main() {
    const int *p = &N1;
    printf("%d\n", *p);
    modify_pointer(&p);
    printf("%d\n", *p);
}