#include <stdio.h>

int main()
{
    setbuf(stdout, 0);
    setbuf(stdin, 0);
    float a, b, c, s;
    printf("Введите первую сторону треугольника: ");
    scanf("%f", &a);
    printf("Введите вторую сторону: ");
    scanf("%f", &b);
    printf("Введите угол между ними: ");
    scanf("%f", &c);

    s = (1.0/2) * a * b * sinf(c);
    printf("Sinus - %f",sinf(c));
    printf("Площадь тревргольника = %f", s);
    return 0;

}
