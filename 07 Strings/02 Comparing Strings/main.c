#include <string.h>
#include <stdio.h>

int main()
{
    char text1[] = "useful";
    char text2[] = "useful";
    char text3[] = "useless";

    printf("%s,%s,strcmp: %d\n", text1, text2, strcmp(text1, text2));
    printf("%s,%s,strcmp: %d\n", text1, text3, strcmp(text1, text3));
    printf("%s,%s,strncmp(4): %d\n", text1, text3, strncmp(text1, text3, 4));
    printf("%s,%s,strncmp(3): %d\n", text1, text3, strncmp(text1, text3, 3));

    
    return 0;
}