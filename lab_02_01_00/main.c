#include <stdio.h>
#include <math.h>

long long sum(long long a, long long *s)
{
    if (a % 2 == 0)
        *s += a;
    return *s;
}

int main()
{
    int i, n;
    long long a[10];
    long long s = 0;
    if (scanf("%d", &n) == 0)
    {
        printf("invalid size value");
        return 1;
    }
    if ((n > 10) || (n <= 0))
    {
        printf("invalid size value");
        return 1;
    }
    for (i = 0; i < n; i++)
    {
        if (scanf("%lld", &a[i]) <= 0)
        {
            printf("invalid element value");
            return 1;
        }
        if ((abs(a[i]) + s) > (pow(2, 63) - 1))
        {
            printf("invalid element value");
            return 1;
        }
        sum(a[i], &s);
    }
    printf("%lld ", s);
    return 0;
}
