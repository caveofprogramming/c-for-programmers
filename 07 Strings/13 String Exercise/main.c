#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool to_number(char text[], int *number)
{
    char *names[] = {"zero", "one", "two", "three", "four", 
                    "five", "six", "seven", "eight", "nine"};

    for(int i=0; i<10; ++i)
    {
        if(strcmp(text, names[i]) == 0)
        {
            *number = i;
            return true;
        }
    }

    return false;
}


int main()
{
    char expression[] = "five six cat three two nine zero";

    char *token = strtok(expression, " ");
    char buffer[20] = "";
    char text[100] = "";

    int total = 0;
    int value = 0;

    while(token)
    {
        if(to_number(token, &value))
        {
            total += value;
            
            if(strlen(text) != 0)
            {
                strcat(text, " + ");
            }

            sprintf(buffer, "%d", value);
            strcat(text, buffer);
        }
        else 
        {
            printf("Invalid token: %s\n", token);
        }

        token = strtok(NULL, " ");
    }

    sprintf(buffer, " = %d", total);
    strcat(text, buffer);

    printf("%s", text);

    return 0;
}