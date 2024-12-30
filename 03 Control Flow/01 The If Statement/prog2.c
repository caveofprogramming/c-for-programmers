#include <stdio.h>

int main() 
{  
    printf("Enter a character > ");

    char c = getchar();

    if(c >= 'A' && c <= 'Z') 
    {
        printf("You entered a capital letter.\n");
    }
    else
    {
        printf("You didn't enter a capital letter.");
    }
    
    return 0;
}