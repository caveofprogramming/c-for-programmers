
#include <stdio.h>

int main()
{
    char value = 0;
    printf("Value: %d\n", value);

    unsigned long size = sizeof(char);
    printf("Size of char: %lu\n", size);

    // Return type of sizeof may be unsigned long long on some platforms.
    // This can be printed with %llu.
    // However, the above code will still work.

    // 1 byte = 8 bits
    // Max: 2^7 - 1 Min: -2^7
    // So the range of a char is usually from -128 to 127.
    value = 127;
    printf("Value: %d\n", value);
    
    value = -128;
    printf("Value: %d\n", value);
}

