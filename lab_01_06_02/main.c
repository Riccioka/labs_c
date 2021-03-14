#include <stdio.h>
#include <math.h>

int func(long xp, long yp, long xa, long ya, long xb, long yb, long xc, long yc)
{
    long ch = ((xp - xa) * (yb - ya) - (yp - ya) * (xb - xa) * (xc - xa) * (yb - ya) - (yc - ya) * (xb - xa));
    if (ch > 0)
        return 0;
    else if (ch == 0)
        return 1;
    else
        return 2;
}

int main()
{
    long xp, yp, xa, ya, xb, yb, xc, yc, d1, d2, d3;
    int res;
    if ((scanf("%ld %ld", &xp, &yp) != 2) || (scanf("%ld %ld", &xa, &ya) != 2) || (scanf("%ld %ld", &xb, &yb) != 2) || (scanf("%ld %ld", &xc, &yc) != 2))
        return -1;
    if ((xc - xa) * (yb - ya) == (yc - ya) * (xb - xa))
        return -1;
    d1 = func(xp, yp, xa, ya, xb, yb, xc, yc);
    d2 = func(xp, yp, xb, yb, xc, yc, xa, ya);
    d3 = func(xp, yp, xc, yc, xa, ya, xb, yb);
    if ((d1 == 0) && (d2 == 0) && (d3 == 0))
        res = 0;
    else if ((d1 == 1) || (d2 == 1) || (d3 == 1))
        res = 1;
    else
        res = 2;
    printf("%d", res);
    return 0;
}
