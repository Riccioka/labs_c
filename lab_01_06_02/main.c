#include <stdio.h>
#include <math.h>

double func(double xp, double yp, double xa, double ya, double xb, double yb)
{
    return (xa - xp) * (yb - ya) - (xb - xa) * (ya - yp);
}

int main()
{
    double xp, yp, xa, ya, xb, yb, xc, yc;
    int res;
    if (scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &xp, &yp, &xa, &ya, &xb, &yb, &xc, &yc) < 8.0)
        return -1;
    if ((fabs((xa - xc) * (yb - yc) - (xb - xc) * (ya - yc)) - 0) < 0.0000001)
        return -1;
    double a = (xa - xp) * (yb - ya) - (xb - xa) * (ya - yp);
    double b = (xb - xp) * (yc - yb) - (xc - xb) * (yb - yp);
    double c = (xc - xp) * (ya - yc) - (xa - xc) * (yc - yp);
        if ((a >= 0 && b >= 0 && c >= 0) || (a <= 0 && b <= 0 && c <= 0))
            res = 0;
        else if (((fabs(a) - 0)< 0.0000001) || ((fabs(b) - 0)< 0.0000001) || ((fabs(c) - 0)< 0.0000001))
            res = 1;
        else
            res = 2;
    printf("%d", res);
    return 0;
}
