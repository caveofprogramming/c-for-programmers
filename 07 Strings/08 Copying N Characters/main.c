#include <stdio.h>
#include <string.h>

int main()
{
    const int SIZE = 20;
    char buffer[SIZE];
    memset(buffer, 'A', SIZE);

    strncpy(buffer, "abcdef", 3);

    printf("%c\n", buffer[3]);

    buffer[3] = 0;
    printf("%s\n", buffer);

    strncpy(buffer, "abcdef", 10);
    printf("%s\n", buffer);
    return 0;
}