#include <stdio.h>

int func(int xp, int yp, int xa, int ya, int xb, int yb)
{
    return (xa - xp) * (yb - ya) - (xb - xa) * (ya - yp);
}

int main()
{
    int xp, yp, xa, ya, xb, yb, xc, yc, res;
    if (scanf("%d %d %d %d %d %d %d %d", &xp, &yp, &xa, &ya, &xb, &yb, &xc, &yc) < 8)
        return -1;
    if (((func(xp, yp, xa, ya, xb, yb) > 0) && (func(xp, yp, xb, yb, xc, yc) > 0) && (func(xp, yp, xc, yc, xa, ya) > 0)) || ((func(xp, yp, xa, ya, xb, yb) < 0) && (func(xp, yp, xb, yb, xc, yc) < 0) && (func(xp, yp, xc, yc, xa, ya) < 0)))
        res = 0;
    else if ((func(xp, yp, xa, ya, xb, yb) * func(xp, yp, xb, yb, xc, yc) * func(xp, yp, xc, yc, xa, ya)) == 0)
        res = 1;
    else
        res = 2;
    printf("%d", res);
    return 0;
}
