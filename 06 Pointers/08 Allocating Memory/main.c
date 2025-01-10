#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int bytes = 1024;

    char *pmem = (char *)malloc(bytes);

    if(pmem == NULL)
    {
        exit(0);
    }

    for(int i=0; i<bytes; ++i)
    {
        pmem[i] = 'a';
    }

    pmem[bytes -1] = 0;
    printf("%s\n", pmem);

    free(pmem);

    return 0;
}