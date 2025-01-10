#include <string.h>
#include <stdio.h>

int main()
{
    char text[] = "hello";

    printf("sizeof: %d\n", (int)sizeof(text));
    printf("strlen: %d\n", (int)strlen(text));
    return 0;
}