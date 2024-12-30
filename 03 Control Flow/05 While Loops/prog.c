#include <stdio.h>

int main()  
{
    int counter = 5;

    while(1)
    {
        if(counter-- < 1)
        {
            break;
        }

        if(counter == 3)
        {
            continue;
        }

        printf("%d ", counter);
    }

    return 0;
}