#include <stdio.h>
#include <math.h>

int func(long xa, long ya, long xb, long yb, long xc, long yc, long xp, long yp)
{
    long ch = (((xp - xa) * (yb - ya) - (yp - ya) * (xb - xa)) * ((xc - xa) * (yb - ya) - (yc - ya) * (xb - xa)));
    if (ch > 0)
        return 0;
    else if (ch == 0)
        return 1;
    else
        return 2;
}

int main()
{
    long xa, ya, xb, yb, xc, yc, xp, yp, d1, d2, d3;
    int res;
    if (scanf("%ld %ld %ld %ld %ld %ld %ld %ld", &xa, &ya, &xb, &yb, &xc, &yc,  &xp, &yp) < 8)
        return -1;
    if ((xc - xa) * (yb - ya) == (yc - ya) * (xb - xa))
        return -1;
    d1 = func(xa, ya, xb, yb, xc, yc, xp, yp);
    d2 = func(xb, yb, xc, yc, xa, ya, xp, yp);
    d3 = func(xc, yc, xa, ya, xb, yb, xp, yp);
    if ((d1 == 0) && (d2 == 0) && (d3 == 0))
        res = 0;
    else if ((d1 == 1) || (d2 == 1) || (d3 == 1))
        res = 1;
    else
        res = 2;
    printf("%d", res);
    return 0;
}
