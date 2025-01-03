#include <stdio.h>

int main()  
{
    int i=0, j=0;
    
    while(i++ < 5)
    {
        while(j++ < 5)
        {
            printf("%d, %d\n", i, j);

            if(i * j > 5)
            {
                goto end_loop;  
            }
        }

        j=0;
    }

    end_loop:

    return 0;
}