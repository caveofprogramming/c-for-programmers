#include <stdio.h>

int main()
{
    char filename[] = "test.bin";

    FILE *fh = fopen(filename, "rb");

    if(!fh)
    {
        printf("Could not open %s.\n", filename);
        return 1;
    }

    int value = 0;
    const int SIZE = 4;
    double values[SIZE] = {};

    int n_objects = (int)fread(&value, sizeof(int), 1, fh);
    printf("Read %d objects.\n", n_objects);
    n_objects = (int)fread(values, sizeof(values[0]), SIZE, fh);
    printf("Read %d objects.\n", n_objects);

    fclose(fh);

    printf("value: %d\n", value);

    for(int i=0; i<SIZE; ++i)
    {
        printf("%.2f ", values[i]);
    }
    printf("\n");

    return 0;
}