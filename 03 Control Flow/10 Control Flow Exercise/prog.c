#include <stdio.h>

int main()  
{
    printf("Enter a number from 0-9: ");
    int number = getchar();

    if(number < '0' || number > '9')
    {
        printf("Invalid input.\n");
        return 1;
    }

    int value = number - '0';

    printf("\n");

    for(int i=1; i<=value; ++i)
    {
        for(int j=1; j<=value; ++j)
        {
            printf("%3d", i*j);
        } 

        printf("\n");
    }

    return 0;
}