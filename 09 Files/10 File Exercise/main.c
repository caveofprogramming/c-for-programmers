/*
 * Create a function that accepts some data for a person
 * and writes that data to a binary file.
 * Create another function that reads the file and displays
 * the information.
 * 
 * Using these functions, write and read two people.
 * 
 * The information accepted should be: name, weight, height
 * 
 * Note: a file can be opened for reading and writing in binary
 * mode by specifying wb+
 * 
 */

#include "person.h"


int main()
{
    char filename[] = "people.bin";

    FILE *fp = fopen(filename, "wb+");

    if(fp == NULL)
    {
        printf("File %s cannot be created.\n", filename);
        return 1;
    }

    char name1[] = "Sue";
    char name2[] = "Peter";
    write_person(fp, name1, strlen(name1), 56.0f, 170.1f);
    write_person(fp, name2, strlen(name2), 75.4f, 180.3f);

    fseek(fp, 0L, SEEK_SET);

    float weight, height;
    const int SIZE = 100;
    char name[SIZE];

    read_person(fp, name, SIZE, &weight, &height);
    printf("Read: %s: weight %.2f, height: %.2f\n", name, weight, height);

    read_person(fp, name, SIZE, &weight, &height);
    printf("Read: %s: weight %.2f, height: %.2f\n", name, weight, height);

    fclose(fp);

    return 0;
}