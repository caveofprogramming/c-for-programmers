#pragma once

typedef enum
{
    READ = 1,   // 001
    WRITE = 2,  // 010
    APPEND = 4, // 100
} flag_t;

void print_flag(flag_t flag);