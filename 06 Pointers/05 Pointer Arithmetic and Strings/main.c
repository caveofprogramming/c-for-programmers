#include <stdio.h>

int main() 
{
    char word1[] = {'h', 'i', 0};
    char word2[] = "hi";

    char text[] = "abcdefghijklmnopqrstuvwxyz";
    printf("%s\n", text);

    char *ptext = text;
    printf("%c\n", *ptext);

    printf("%c\n", *(ptext + 25));
    ptext += 26;
    printf("%d\n", *ptext);
    ptext -= 26;

    printf("%s\n", ptext + 5);
    printf("%c\n", ptext[4]);

    return 0;
}