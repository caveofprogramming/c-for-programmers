#include <stdio.h>

int main()  
{
    struct Person
    {
        int id;

        struct
        {
            float weight;
            float height;
        } data;
    };

    struct Person bob = { 21, { 75.1f, 178.2f }};

    printf("Bob: %d, %.1f, %.1f", bob.id, bob.data.weight, bob.data.height);
    return 0;
}