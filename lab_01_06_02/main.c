#include <stdio.h>
#include <math.h>

double func(double xp, double yp, double xa, double ya, double xb, double yb)
{
    return (xa - xp) * (yb - ya) - (xb - xa) * (ya - yp);
}

int check_side(double d1, double d2, double d3)
{
    int zeros = (fabs(d1 - 0) < 0.0000001) + (fabs(d2 - 0) < 0.0000001) + (fabs(d3 - 0) < 0.0000001);
    return (zeros == 2 ||
        (zeros == 1 && (d1 * d2 > 0 || d1 * d3 > 0 || d3 * d2 > 0)));
}

int main()
{
    double xp, yp, xa, ya, xb, yb, xc, yc;
    double d1, d2, d3;
    int res;
    if (scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &xp, &yp, &xa, &ya, &xb, &yb, &xc, &yc) < 8)
        return -1;
    if ((fabs((xa - xc) * (yb - yc) - (xb - xc) * (ya - yc)) - 0) < 0.0000001)
        return -1;
    d1 = func(xp, yp, xa, ya, xb, yb);
    d2 = func(xp, yp, xb, yb, xc, yc);
    d3 = func(xp, yp, xc, yc, xa, ya);
    if ((d1 > 0.0 && d2 > 0.0 && d3 > 0.0) || (d1 < 0.0 && d2 < 0.0 && d3 < 0.0))
        res = 0;
    else if (check_side(d1, d2, d3))
        res = 1;
    else
        res = 2;
    printf("%d", res);
    return 0;
}
