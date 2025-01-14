#include <stdio.h>
#include "main.h"

int main()
{
    char filename[] = "test.bin";

    FILE *fh = fopen(filename, "wb");

    if(!fh)
    {
        printf("Could not open %s.\n", filename);
        return 1;
    }

    data_t data;
    fill_struct(&data);
    print_struct(&data);
    int nwritten = fwrite(&data, sizeof(data), 1, fh);

    fclose(fh);

    printf(nwritten ? "Written %s\n": "Error writing %s\n", filename);

    return 0;
}