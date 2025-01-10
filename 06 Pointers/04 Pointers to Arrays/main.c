#include <stdio.h>

int main()
{
    int values[] = {0, 2, 4, 5, 6, 8};

    int *pvalues = values;

    printf("size of pvalues: %lu\n", sizeof(pvalues));

    for(int i=0; i<sizeof(values)/sizeof(int); ++i)
    {
        printf("%d ", *pvalues);
        ++pvalues;
    }

    printf("\n%lu\n", pvalues - values);

    return 0;
}