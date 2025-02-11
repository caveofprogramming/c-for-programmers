#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    const int SIZE = 1024;

    char *text = (char *)malloc(SIZE);

    if(!text)
    {
        puts("Unable to allocate memory.");
        return 0;
    }

    memset(text, 0, SIZE);
    memset(text, 'e', 20);
    puts(text);

    free(text);
    return 0;
}