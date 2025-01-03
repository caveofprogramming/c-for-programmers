#include <stdio.h>
#include <stdbool.h>

void show_info(int employee_id, bool on_holiday)
{
    printf("Employee: %d, on holiday: %d", employee_id, on_holiday);
}

int main() 
{
    show_info(123, true);
    return 0;
}

