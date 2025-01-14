#include <stdio.h>

int main()
{
    char filename[] = "test.bin";

    FILE *fh = fopen(filename, "wb");

    if(!fh)
    {
        printf("Could not write %s.\n", filename);
        return 1;
    }

    int value = 1234;

    const int SIZE = 4;
    double values[SIZE] = {6.1, 7.2, 8.3, 9.4};

    fwrite(&value, sizeof(int), 1, fh);
    fwrite(values, sizeof(values[0]), SIZE, fh);

    fclose(fh);

    printf("Written %s.\n", filename);

    return 0;
}