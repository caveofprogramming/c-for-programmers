#include <stdio.h>
#include <stdint.h> 

// 1001 & 1100 => 1000

int main()
{
    uint32_t value1 = 0x12345678;
    printf("%08x\n", value1);

    uint32_t value2 = value1 & 0xFF00FF00;
    printf("%08x\n", value2);

    value1 &= 0xFF000000;
    printf("%08x\n", value1);
    
    return 0;
}