#include <stdio.h>

int main()  
{
    int counter = 0;

    do
    {
        counter++;
        printf("%d ", counter);
    }
    while(counter < 5);

    return 0;
}