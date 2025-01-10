#include <stdio.h>

double multiply(int n, double d)
{
    return n*d;
}

int main()
{
    double (*pfunc)(int, double) = &multiply;

    double result = (*pfunc)(5, 2.0);

    printf("result: %.2f\n", result);
    return 0;
}