#include <stdio.h>
#include "action.h"

#define OK 0

int main(int argc, char **argv)
{
    FILE *f;
    float a = 0;
    int res = 0;
    float c = 0;
    int count = 0;

    if (argc != 2 || (f = fopen(argv[1], "r")) == NULL|| getc(f) == EOF || feof(f) || action(f, &c))
        return -1;

    rewind(f);

    while ((res = fscanf(f, "%f", &a)) == 1)
        if (a > c)
            count++;
    if (!feof(f))
        return -1;
    printf("%d", count);
    fclose(f);

    return 0;
}
