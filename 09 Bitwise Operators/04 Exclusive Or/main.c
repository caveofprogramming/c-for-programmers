#include <stdio.h>
#include "flags.h"


// 1101 ^ 0110 => 1011

int main()
{
    flag_t flags = READ;
    print_flag(flags);

    flags |= WRITE;
    print_flag(flags);

    flags |= WRITE;
    print_flag(flags);

    flags ^= APPEND;
    print_flag(flags);

    flags ^= APPEND;
    print_flag(flags);

    
    
    return 0;
}