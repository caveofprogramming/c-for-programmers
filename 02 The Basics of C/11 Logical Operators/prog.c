#include <stdio.h>

int main() 
{
    // ==, !=, &&, ||, !, <, >, <=, >=

    printf("7 == 7: %d\n", 7 == 8);
    printf("7 > 10: %d\n", 7 != 10);
    printf("!(7 <= 5): %d\n", !(7 <= 5));
    printf("!(7 <= 5): %d\n", 3 == 0 || 2 == 2);

    return 0;
}