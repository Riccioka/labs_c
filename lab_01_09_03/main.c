#include <stdio.h>
#include <math.h>

double f()
{
    double x = 0;
    int n = 1;
    double pr = 1;
    while (x >= 0)
    {
        scanf("%lf", &x);
        if (x >= 0)
        {
            pr *= (x + n);
            n++;
        }
    }
    return exp(1 / pr);
}

int main()
{
    double res = f();
    printf("%lf", res);
    return 0;
}
