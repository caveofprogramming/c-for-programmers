#include <stdio.h>

int main() 
{
    int temperature = 5;

    if(temperature < 0)
    {
        printf("Freezing.\n");
    }
    else if(temperature < 4)
    {
        printf("OK.\n");
    }
    else
    {
        printf("Too warm.\n");
    }

    if(1)
        printf("True!");
    
    return 0;
}