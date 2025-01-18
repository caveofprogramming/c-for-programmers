/*
 * Create two functions.
 *
 * The first function accepts a 32-bit int and three pointers to char values,
 * named red, green and blue. It sets the values of the chars equal to the
 * respective values of the three least significant bytes in the int value.
 * 
 * It sets the value of the blue char from the least significant byte of
 * the int, green from the second least significant, and red from the third.
 * 
 * For example, an input of 0x00123456 gives us chars with values:
 * red: 0x12, green: 0x34, blue: 0x56.
 * 
 * The second function does the reverse; three red, green and blue char values
 * and returns a 32-bit int made by combining those values.
 * 
 * Use bitshift operators to do this.
 * 
 * Bonus: implement the functions again using unions, not bitshifting.
 */

#include <stdio.h>
#include <stdint.h>
#include "color.h"

int main()
{
    char red, green, blue;

    int_to_color(0x00123456, &red, &green, &blue);
    printf("00%02x%02x%02x\n", red, green, blue);

    uint32_t color = color_to_int(red, green, blue);
    printf("%08x\n", color);
    return 0;
}