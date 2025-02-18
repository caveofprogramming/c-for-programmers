#include "fibonacci.h"

void fibonacci(int values[], int number_values)
{
    if(number_values < 1)
    {
        return;
    }
    
    values[0] = 0;
    
    if(number_values > 1)
    {
        values[1] = 1;
    }

    for(int i=2; i<=number_values; ++i)
    {
        values[i] = values[i-1] + values[i-2];
    }
}