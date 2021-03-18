#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

long long sum(long long a, long long *s)
{
    if (a % 2 == 0)
        *s += a;
    return *s;
}

int main()
{
    int i;
    long long n;
    long long a[10];
    long long s = 0;
    if (scanf("%lld", &n) <= 0 || n > 10 || n <= 0)
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
        if (llabs(a[i]) + s > INT_MAX)
        {
            printf("invalid element value");
            return 1;
        }
        sum(a[i], &s);
    }
    printf("%lld ", s);
    return s == 0;
}
