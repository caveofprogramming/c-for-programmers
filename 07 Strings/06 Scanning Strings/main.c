
#include <stdio.h>

int main()
{
    char text1[] = "Hello 123";

    char string[10];
    int value = 0;
    int tokens = sscanf(text1, "%20s%d", string, &value);
    printf("%d tokens. Found: '%s', %d\n", tokens, string, value);
    
    return 0;
}