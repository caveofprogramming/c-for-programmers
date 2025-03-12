#include <stdio.h>

int main()
{
    char text[] = "Hello!";

    char const *ptext1 = text;
    //ptext[5] = '?';
    ptext1++;

    char * const ptext2 = text;
    ptext2[5] = '?';
    //ptext2++;

    printf("%s\n", ptext1);
    printf("%s\n", ptext2);

    return 0;
}