#include <stdio.h>

int main()
{
    int a, p, f, s, t;
    scanf("%d", &a);
    p = 1;
    t = a % 10;
    s = a / 10 % 10;
    f = a / 100;
    p = t * s * f;
    printf("%d", p);
    return 0;
}
