#include <stdio.h>

typedef struct s_point
{
    double x;
    double y;
}               t_point;

double func(t_point p1, t_point p2, t_point p3)
{
    return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

int main(void)
{
    t_point p, a, b, c;
    int res;

    if (scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &p.x, &p.y, &a.x, &a.y, &b.x, &b.y, &c.x, &c.y) != 8)
        return 1;
    if ((func(p, a, b) > 0 && func(p, b, c) > 0 && func(p, c, a) > 0) || (func(p, a, b) < 0 && func(p, b, c) < 0 && func(p, c, a) < 0))
        res = 0;
    else if (func(p, a, b) * func(p, b, c) * func(p, c, a) == 0)
        res = 1;
    else
        res = 2;
    printf("%d", res);
    return 0;
}
