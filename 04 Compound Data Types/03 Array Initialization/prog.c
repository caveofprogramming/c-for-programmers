#include <stdio.h>
#include <memory.h>

int main()  
{
    // TODO, used const originally
    #define SIZE 3

    int values1[SIZE];
    memset(values1, 0, sizeof(values1)); // Not portable

    for(int i=0; i < SIZE; ++i)
    {
        printf("%d ", values1[i]);
    } 

    int values2[SIZE] = {0}; // C89
    int values3[SIZE] = {7, 8};

    printf("\n");

    for(int i=0; i < SIZE; ++i)
    {
        printf("%d ", values3[i]);
    } 

    int values4[SIZE] = {[0]=10, [2]=30}; //C99

    printf("\n");
    for(int i=0; i < SIZE; ++i)
    {
        printf("%d ", values4[i]);
    } 

    int values5[SIZE] = {}; // C23

    return 0;
}