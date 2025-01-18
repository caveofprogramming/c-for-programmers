#include <stdio.h>

int main()
{
    printf("Enter an int: ");
    
    int value;
    int tokens = scanf("%d", &value);

    if(tokens == 1)
    {
        printf("You entered: %d\n", value);
    }
    else
    {
        printf("%d tokens. You didn't enter an int.\n", tokens);
    }

    
    return 0;
}