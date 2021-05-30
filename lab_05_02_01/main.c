#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define OK 0

int main(int argc, char **argv)
{
    FILE *f;
    float min = __FLT_MAX__;
    float max = __FLT_MIN__;
    float a = 0;
    int res = 0;

    if (argc != 2 || (f = fopen(argv[1], "r")) == NULL || getc(f) == EOF)
        return -1;

    fseek(f, 0, SEEK_SET);

    while ((res = fscanf(f, "%f", &a)) == 1)
    {
        if (a < min)
            min = a;
        if (a > max)
            max = a;
    }
    if (res != EOF)
        return -1;

    float c = (min + max) / 2;
    int count = 0;
    rewind(f);

    while ((res = fscanf(f, "%f", &a)) == 1)
        if (a > c)
            count++;
    if (res != EOF)
        return -1;
    printf("%d", count);
    fclose(f);

    return 0;
}
