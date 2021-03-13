#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c, s;
    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);
    c = c * M_PI / 180;
    s = (1.0 / 2) * a * b * sin(c);
    printf("%lf", sin(c));
    printf("%lf", s);
    return 0;
}
