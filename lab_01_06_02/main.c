#include <stdio.h>

int func(float xp, float yp, float xa, float ya, float xb, float yb)
{
    return  ((xa - xp) * (yb-ya) - (xb - xa) * (ya - yp));
}

int main()
{
    double xp, yp, xa, ya, xb, yb, xc, yc;
    int r = scanf("%lf", &xp);
    if (r == 0)
        return 1;
    r = scanf("%lf", &yp);
    if (r == 0)
        return 1;
    r = scanf("%lf", &xa);
    if (r == 0)
        return 1;
    r = scanf("%lf", &ya);
    if (r == 0)
        return 1;
    r = scanf("%lf", &xb);
    if (r == 0)
        return 1;
    r = scanf("%lf", &yb);
    if (r == 0)
        return 1;
    r = scanf("%lf", &xc);
    if (r == 0)
        return 1;
    r = scanf("%lf", &yc);
    if (r == 0)
        return 1;
    if ((func(xp, yp, xa, ya, xb, yb) > 0) && (func(xp, yp, xb, yb, xc, yc) > 0) && (func(xp, yp, xc, yc, xa, ya) > 0))
        printf("0");
    else if ((func(xp, yp, xa, ya, xb, yb) < 0) && (func(xp, yp, xb, yb, xc, yc) < 0) && (func(xp, yp, xc, yc, xa, ya) < 0))
        printf("0");
    else if ((func(xp, yp, xa, ya, xb, yb)) * (func(xp, yp, xb, yb, xc, yc)) * (func(xp, yp, xc, yc, xa, ya)) == 0)
        printf("1");
    else
        printf("2");
    return 0;
}
