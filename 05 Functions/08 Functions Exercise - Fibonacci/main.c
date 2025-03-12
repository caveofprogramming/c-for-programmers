/*
 * Create a function that fills an array with the first
 * n numbers of the Fibonacci sequence.
 * 0, 1, 1, 2, 3, 5, 8, 13, 21 ...
 * - where each number is derived by adding the previous two
 * numbers together.
 * 
 * The function should receive two arguments: an array to
 * fill with numbers, and the number of values to place
 * in the array.
 * 
 * Place the function in a .c file, but also create a header
 * file containing its prototype.
 */

#include <stdio.h>
#include "fibonacci.h"

int main() 
{
    const int n_values = 10;
    int values[n_values];
    fibonacci(values, n_values);

    for(int i=0; i<n_values; ++i)
    {
        printf("%d ", values[i]);
    }
    printf("\n");

    return 0;
}