#include <stdio.h>

#pragma pack(push,1)

typedef struct
{
    float v1;
    char v2;
} value1_t;

#pragma pack(pop)

typedef struct
{
    float v1;
    char v2;
} value2_t;

int main()
{
    printf("%lu\n", sizeof(value1_t));
    printf("%lu\n", sizeof(value2_t));
    return 0;
}



