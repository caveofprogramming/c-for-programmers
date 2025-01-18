#include <stdio.h>

int main()
{
    int temperature = 4;

    int cooling = temperature > 3 ? 1: 0;
    printf("Cooling: %d\n", cooling);

    printf("Cooling is %s", cooling ? "ON":"OFF");
    return 0;
}