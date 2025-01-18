#include <stdio.h>


int main()
{
    char *texts[] = {"Hello", "to", "you"};

    printf("%s\n", texts[0]);
    printf("%s\n", texts[1]);
    printf("%s\n", texts[2]);

    printf("%lu\n", sizeof(texts));
    return 0;
}