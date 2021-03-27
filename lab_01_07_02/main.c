#include <stdio.h>
#include <math.h>

double arcsinus(double x, double eps)
{
    double s = x;
    double atmp = x;
    int n = 0;

    while (fabs(atmp) > eps)
    {
        atmp *= atmp * atmp * (n - 1) * (n - 1) / (n * (n + 1));
        s += atmp;
        n += 2;
    }
    return s;
}

int main(void)
{
    double x, e, f, s, d1, d2;
    if (scanf("%lf", &x) == 0 || scanf("%lf", &e) == 0 || x > 1 || x < -1)
        return 1;
    f = asin(x);
    if (e < 0 || e >= 1)
        return 1;
    s = arcsinus(x, e);
    d1 = fabs(f - s);
    d2 = d1 / fabs(f);
    printf("%lf %lf %lf %lf", s, f, d1, d2);
    return 0;
}
