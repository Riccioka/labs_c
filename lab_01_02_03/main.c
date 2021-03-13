#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c, s;
    printf("Введите первую сторону треугольника: ");
    scanf("%lf", &a);
    printf("Введите вторую сторону: ");
    scanf("%lf", &b);
    printf("Введите угол между ними: ");
    scanf("%lf", &c);
    c = c * M_PI / 180;
    s = (1.0/2) * a * b * sin(c);
    printf("Sinus - %lf", sin(c));
    printf("Площадь треугольника = %lf", s);
    return 0;
}
