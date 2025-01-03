#include <stdio.h>

int main()  
{
    struct Person 
    {
        int id;
        float height;
    };

    struct Person bob = {22, 1.82f};

    bob.id = 21;
    bob.height = 1.78f;

    printf("Bob: %d, %.1f\n", bob.id, bob.height);

    return 0;
}