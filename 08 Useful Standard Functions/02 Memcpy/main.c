#include <stdio.h>
#include <string.h>

int main()
{
    char text1[] = "Hello there";

    const int BUFFSIZE = strlen(text1) + 1;
    char text2[BUFFSIZE];

    memcpy(text2, text1, BUFFSIZE);

    puts(text2);
    return 0;
}