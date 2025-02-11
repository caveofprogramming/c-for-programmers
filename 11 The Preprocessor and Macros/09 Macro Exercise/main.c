/*
 * Write a macro SUM_PRINT that accepts two variables and prints
 * [first variable name] + [second variable name] = [sum]
 * 
 * For example, if:
 *      int value1 = 7
 * and
 *      int value2 = 8
 * 
 * Then SUM_PRINT(value1, value2)
 * 
 * prints:
 * 
 *      value1 + value2 = 15
 *
 */

#include <stdio.h>

#define SUM_PRINT(X, Y) printf("%s + %s = %d", #X, #Y, X+Y);

int main()
{
    int cats = 8;
    int dogs = 9;

    SUM_PRINT(cats, dogs)
    return 0;
}