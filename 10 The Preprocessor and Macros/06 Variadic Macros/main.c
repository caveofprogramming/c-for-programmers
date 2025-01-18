#include <stdio.h>

#define PRINT(...) printf(__VA_ARGS__);

int main()
{
    PRINT("%s: %d\n", "value", 7)
    return 0;
}