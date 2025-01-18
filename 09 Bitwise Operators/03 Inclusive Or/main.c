#include <stdio.h>
#include <stdint.h> 

// 1001 | 1100 => 1101

int main()
{
    uint32_t value1 = 0x12000000;
    printf("%08x\n", value1);

    uint32_t value2 = 0x00003400;
    printf("%08x\n", value2);

    uint32_t value3 = value1 | value2;
    printf("%08x\n", value3);

    printf("%08x\n", value1 |= 0x00000078);
    
    return 0;
}