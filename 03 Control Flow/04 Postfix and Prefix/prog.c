#include <stdio.h>

int main()
{
    int value = 0;
    printf("value: %d\n", value++);
    printf("value: %d\n", value);

    printf("\n");

    value = 0;
    printf("value: %d\n", ++value);
    printf("value: %d\n", value);

    printf("\n");

    /*
     * Originally I included the following in the video,
     * as an example of a horrendous interview question that
     * I have actually been asked about in an interview.
     * What does it evaluate to?
     * No-one should ever write C code like this.
     * However, I've since realised that the behaviour of
     * this expression is actually not defined by the C 
     * standard. What you get, depends on your compiler.
     */
    
    value = 1;
    printf("Result: %d\n", 2 * value++ + ++value);
}
