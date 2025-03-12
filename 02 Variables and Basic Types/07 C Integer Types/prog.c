
#include <stdio.h>

/*
 *
 * char, short int, int, long int, long long int
 * 
 * Example output on Windows:
 * Size of char: 1
 * Size of short int: 2
 * Size of int: 4
 * Size of long int: 4
 * Size of long long int: 8
 *  
 * Note: mingw on Windows gives me warning with the -Wall
 * compiler option (which turns on all warnings)
 * because sizeof returns long long unsigned int on my
 * Windows machine.
 * The format specifier should then ideally be %llu.
 */

int main()
{
    printf("Size of char: %lu\n", sizeof(char));
    printf("Size of short int: %lu\n", sizeof(short));
    printf("Size of int: %lu\n", sizeof(int));
    printf("Size of long int: %lu\n", sizeof(long));
    printf("Size of long long int: %lu\n", sizeof(long long));

    return 0;
}

