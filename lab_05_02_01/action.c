#include <stdio.h>
#include <float.h>

int action(FILE *f, float *c)
{
    int res = 0;
    float a = 0;
    float min = 3.40282e+38;
    float max = 1.17549e-38;

    while ((res = fscanf(f, "%f", &a)) == 1)
    {
        if (a < min)
            min = a;
        if (a > max)
            max = a;
    }
    *c = (min + max) / 2;

    if (res != EOF)
        return -1;

    return res;
}
