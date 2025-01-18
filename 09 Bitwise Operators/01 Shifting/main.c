#include <stdio.h>
#include <stdint.h> 

// 0110 << 1 => 1100
// 0011 >> 1 => 0001

int main()
{
    uint32_t value1 = 0x000000FF;
    printf("%08X\n", value1);

    uint32_t value2 = value1 << 8;
    printf("%08X\n", value2);

    value2 <<= 8;
    printf("%08X\n", value2);

    value2 >>= 16;
    printf("%08X\n", value2);

    int value3 = 27;
    printf("%d\n", value3 << 1);

    return 0;
}