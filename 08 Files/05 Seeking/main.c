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

    fseek(fh, (long)sizeof(int), SEEK_SET);
    fseek(fh, 3L * sizeof(double), SEEK_CUR);

    double value = 0.0;
    fread(&value, sizeof(double), 1, fh);

    fclose(fh);

    printf("value: %.2f\n", value);

    return 0;
}