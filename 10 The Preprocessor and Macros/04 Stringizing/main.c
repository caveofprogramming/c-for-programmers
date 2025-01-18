#include <stdio.h>

#define DEBUG(X) fprintf(stderr, "%s\n", #X);

int main()
{
    DEBUG(some error message)

    return 0;
}