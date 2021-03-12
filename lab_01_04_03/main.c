#include <stdio.h>

int main()
{
    int a, p;

    printf("Число = ");
    scanf("%d", &a);

    p = 1;
    for(int i=1; i<=3; i++)
    {
        p *= a % 10;
        a /= 10;
    }

    printf("Произведение цифр = %d", p);
    return 0;
}
