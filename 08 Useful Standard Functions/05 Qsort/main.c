#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int numbers[] = {7, 3, 8, 2, 5, 9, 4, 6, 1};
    qsort(numbers, sizeof(numbers)/sizeof(int), sizeof(int), compare);

    for(int i=0; i<sizeof(numbers)/sizeof(int); ++i)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}