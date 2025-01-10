#include <stdio.h>

int *get_value()
{
    int value = 7;
    return &value; // Never do this! value is out of scope.
}

//NEVER DO THIS!
char *get_array()
{
    char text[] = "Hello";
    return text; // Never do this! text is out of scope.
}

int main()
{
    int *pi = get_value();
    printf("%d\n", *pi);

    char *ptext = get_array();
    printf("%s\n", ptext);
    return 0;
}