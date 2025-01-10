#include <stdio.h>

double multiply(int n, double d)
{
    return n*d;
}

double (*get_op())(int, double)
{
    return &multiply;
}

int main()
{
    double (*pfunc)(int, double) = get_op();
    printf("result: %.2f\n", (*pfunc)(2, 5.0));
    return 0;
}