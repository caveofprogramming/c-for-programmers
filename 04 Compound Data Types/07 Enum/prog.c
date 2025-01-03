#include <stdio.h>

int main()  
{
    enum Fruit
    {
        APPLE = 20,
        BANANA,
        ORANGE = 30,
        CHERRY
    };

    enum Fruit fruit = APPLE;
    printf("Fruit: %d\n", fruit);

    printf("Enum: %d, %d, %d, %d\n", APPLE, BANANA, ORANGE, CHERRY);

    return 0;
}