#include <stdio.h>

int main()
{
    int a, p;

    printf("Число = ");
    scanf("%d", &a);

    p = 1;
    while (a > 0)
    {
        p *= a % 10;
        a /= 10;
    }

    printf("Произведение цифр = %d", p);
    return 0;
}
