#include <stdio.h>

int main()  
{
    const int ROWS = 2;
    const int COLS = 3;
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