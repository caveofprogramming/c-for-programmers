#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(char *)a - *(char *)b);
}

int main()
{
    char numbers[] = {7, 3, 8, 2, 5, 9, 4, 6, 1};
    qsort(numbers, sizeof(numbers), 1, compare);

    for(int i=0; i<sizeof(numbers); ++i)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}