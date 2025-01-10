#include <stdio.h>
static int count;

void inc_count()
{
    ++count;
}

void show_count()
{
    static int runs;
    printf("count %d: %d\n", runs, count);
    runs++;
}