#include "person.h"

/*
 * name: char array containing name
 * name_size: number of characters in name
 * weight: weight in kg
 * height: height in cm
 * 
 * returns: true on success, else false
 */
bool write_person(FILE *fp, char *name, int name_size, float weight, float height)
{
    person_t person;
    person.name_size = name_size;
    person.weight = weight;
    person.height = height;

    int written = fwrite(&person, sizeof(person), 1, fp);
    written += fwrite(name, (size_t)name_size, 1, fp);

    return written == 2 ? true: false;
}

/*
 * name: char array at name_size bytes.
 * name_size: maximum number of characters to read for name
 * weight: address of float to hold weight in kg
 * height: address of float to hold height in cm
 * 
 * returns: true on success, else false
 */
bool read_person(FILE *fp, char *name, int name_size, float *weight, float *height)
{
    person_t person;
    
    int read = fread(&person, sizeof(person), 1, fp);

    if(read != 1)
    {
        fprintf(stderr, "Unable to read from file.\n");
        return false;
    }

    if(person.name_size >= name_size)
    {
        fprintf(stderr, "Name found in file is %d characters.\n", 
            person.name_size);
        return false;
    }

    *weight = person.weight;
    *height = person.height;

    read += fread(name, (size_t)person.name_size, 1, fp);
    name[person.name_size] = 0;

    return read == 2 ? true: false;
}