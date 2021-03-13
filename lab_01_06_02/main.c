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
    printf("%d", res);
    return 0;
}
