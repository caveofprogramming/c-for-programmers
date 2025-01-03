#include <stdio.h>

int main()  
{
    union Value
    {
        int driving_id;
        int passport_id;
    };

    union Value v;

    v.driving_id = 123;

    printf("size of v: %lu\n", sizeof(v));
    
    printf("driving ID: %d\n", v.driving_id);
    printf("passport ID: %d\n", v.passport_id);

    return 0;
}