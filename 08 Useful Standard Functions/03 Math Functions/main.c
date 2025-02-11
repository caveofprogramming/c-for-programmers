#include <math.h>
#include <stdio.h>

int main()
{
    const double PI = 3.141592;

    printf("2^3 = %.2f\n", pow(2, 3));
    printf("round(3.1): %.2f\n", round(3.1));
    printf("ceil(3.1): %.2f\n", ceil(3.1));
    printf("sin(2 * PI): %.2f\n", sin(2 * PI));

    return 0;
}