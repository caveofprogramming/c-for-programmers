#include <stdio.h>
#include "main.h"

int main()
{
    char filename[] = "test.bin";

    FILE *fh = fopen(filename, "rb");

    if(!fh)
    {
        printf("Could not open %s.\n", filename);
        return 1;
    }

    data_t data;
    int nread = fread(&data, sizeof(data), 1, fh);
    print_struct(&data);

    fclose(fh);

    printf(nread ? "Read %s\n": "Error reading %s\n", filename);

    return 0;
}