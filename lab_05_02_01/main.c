#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "process.h"

#define OK 0

int main()
{
    char name[256];
    scanf("%s", &name);
    FILE *f;
    float min = __FLT_MAX__;
    float max = __FLT_MIN__;
    float a = 0;

    if ((f = fopen("name", "r+")) == NULL)
    {
        printf("");
        return 1;
    }

    while (fscanf (f, "%f", &a) != EOF)
    {
        if (a < min)
            min = a;
        if (a > max)
            max = a;
    }

    float c = (min + max) / 2;
    int count = 0;
    rewind(f);

    while (fscanf (f, "%f", &a) != EOF)
    {
        if (a > c)
            count++;
    }
    fprintf(f, "\n%d", count);
    fclose(f);

    return 0;
}
