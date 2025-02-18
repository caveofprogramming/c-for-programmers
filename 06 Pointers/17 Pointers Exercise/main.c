#include <stdio.h>

int main() 
{
    char text[] = "The fence is not made of sausages.";

    char *ptext = text;
    char *pend = text + sizeof(text) - 2;

    char c;

    while(ptext < pend)
    {
        c = *ptext;
        *ptext = *pend;
        *pend = c;
        ++ptext;
        --pend;
    }

    printf("%s\n", text);

    return 0;
}