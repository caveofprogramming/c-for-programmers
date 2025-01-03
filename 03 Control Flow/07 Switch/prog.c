#include <stdio.h>

int main()  
{
    int value = 4;

    switch(value)
    {
        case 1:
            printf("Got one");
            break;
        case 2:
            printf("Got two");
            break;
        case 3:
            printf("Got three");
            break;
        default:
            printf("Something else.");
    }
    
    return 0;
}