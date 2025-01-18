#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#pragma pack(push, 1)

typedef struct 
{
    int name_size;
    float height;
    float weight;
} person_t;

#pragma pack(pop)

bool write_person(FILE *fp, char *name, int name_size, float weight, float height);
bool read_person(FILE *fp, char *name, int name_size, float *weight, float *height);
