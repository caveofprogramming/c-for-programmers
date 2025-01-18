#include <string.h>
#include <stdio.h>
#include "flags.h"

void print_flag(flag_t flag)
{
    flag_t constants[] = {READ, WRITE, APPEND};
    char symbols[] = "RWA";

    for(int i=0; i < strlen(symbols); ++i)
    {
        if(flag & constants[i])
        {
            printf("%c", symbols[i]);
        }
    }
    printf("\n");
}
