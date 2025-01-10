#include <stdio.h>

typedef double (*op_t)(int, double);

double multiply(int n, double d)
{
    return n*d;
}

op_t get_op()
{
    return &multiply;
}

int main()
{
    op_t pfunc = get_op();
    printf("result: %.2f\n", (*pfunc)(2, 5.0));
    return 0;
}