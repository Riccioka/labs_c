#include <stdio.h>
#include <float.h>

int action(FILE *f, float *c)
{
    float a = 0;
    float min = 3.40282e+38;
    float max = 1.17549e-38;

    while (fscanf(f, "%f", &a) == 1)
    {
        if (a < min)
            min = a;
        if (a > max)
            max = a;
    }
    *c = (min + max) / 2;

    if (!feof(f))
        return -1;

    return 0;
}
