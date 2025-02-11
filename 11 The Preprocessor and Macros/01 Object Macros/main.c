#include <stdio.h>
#include "main.h"

int main() 
{
    printf("%.3f\n", PI);
    printf("%s\n", NAME);

    char *days[] = DAYS;

    for(int i=0; i < DAYS_IN_WEEK; ++i)
    {
        printf("%s\n", days[i]);
    }

    return 0;
}