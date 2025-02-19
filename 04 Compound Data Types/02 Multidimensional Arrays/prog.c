#include <stdio.h>

int main()  
{
    // TODO: Variable-sized arrays are allowed in C99, but I find mingw still gives
    // an error if I used constants here instead of defines.
    // error: variable-sized object may not be initialized except with an empty initializer
    #define ROWS 2
    #define COLS 3
    double table[ROWS][COLS] = {{1.1, 2.1, 3.1}, {4.2, 5.2, 6.2}};

    printf("Item at 1,2: %.1f\n", table[1][2]);

    printf("\n");
    
    for(int i=0; i < ROWS; ++i)
    {
        for(int j=0; j < COLS; ++j)
        {
            printf("%4.1f", table[i][j]);
        }
        printf("\n");
    }

    return 0;
}