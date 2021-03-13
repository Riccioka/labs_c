#include <stdio.h>
#include <math.h>

double arcSin(x, eps)
{
    double s = x;
    double atmp = x;
    int n = 0;
    while (fabs(atmp) > eps)
    {
        atmp = atmp * ((2 * n + 2) * (2 * n + 1) * x * x * (2 * n + 1)) / (4 * (n + 1) * (n + 1) * (2 * n + 3));
        s += atmp;
        n++;
    }
    return s;
}

int main()
{
    double x, e, f, s, d1, d2;
    int r = scanf("%lf", &x);
    if (r == 0 || (x > 1) || (x < -1))
        return 1;
    r = scanf("%lf", &e);
    if(r == 0)
        return 1;
    f = asin(x);
    s = arcSin(x, e);
    d1 = fabs(f - s);
    d2 = d1 / f;
    printf("%.12lf %.12lf %.12lf %.12lf", s, f, d1, d2);
    return 0;
}
