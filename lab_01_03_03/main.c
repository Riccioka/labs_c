#include <stdio.h>
#include <math.h>

int main()
{
    float v, a, t, s;
    printf("Введите начальную скорость: ");
    scanf("%f", &v);
    printf("Введите ускорение: ");
    scanf("%f", &a);
    printf("Введите время движения: ");
    scanf("%f", &t);
    s = v * t + (a * pow(t, 2)) / 2;
    printf("Перемещение = %f", s);
    return 0;
}
