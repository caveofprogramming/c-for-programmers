#include <stdlib.h>
#include <stdio.h>

int main()
{
    char buffer[10];

    // itoa(255, buffer, 10); // Non-standard
    sprintf(buffer, "%d", 255);

    puts(buffer);

    printf("%d\n", atoi(buffer));
    printf("%f\n", atof(buffer));
    return 0;
}