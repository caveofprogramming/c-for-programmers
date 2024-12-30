#include <stdio.h>

int main() 
{
    int value1 = 10;
    double value2 = (double)value1;
    printf("value2: %f\n", value2);

    double value3 = 7.89;
    int value4 = (int)value3;
    printf("value4: %d\n", value4);

    int value5 = 260;
    char value6 = (char)value5;
    printf("value6: %d\n", value6); 

    return 0;
}