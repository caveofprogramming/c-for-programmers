#include <stdio.h>

int main()
{
    char text[50];
    char name[] = "Bob";

    sprintf(text, "I am %s and I am %d years old.", name, 100);

    printf("%s\n", text);
    return 0;
}