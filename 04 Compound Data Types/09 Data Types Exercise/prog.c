#include <stdio.h>

int main()  
{
    struct Counter 
    {
        int value1;
        int value2;
    };

    const int SIZE = 10;

    struct Counter values[SIZE];

    for(int i=0; i < SIZE; ++i)
    {
        values[i].value1 = i;
        values[i].value2 = SIZE - i;
    }

    for(int i=0; i < SIZE; ++i)
    {
        printf("%d-%d\n", values[i].value1, values[i].value2);
    }

    return 0;
}