#include <stdio.h>

long long sum(long long *a, int n)
{
    long long s = 0;
    int i;
    for (i = 0; i < n; i++)
        if (a[i] % 2 == 0)
            s += a[i];
    return s;
}

int main()
{
    int i, n;
    long long a[10];
    if (scanf("%d", &n) == 0)
    {
        printf("invalid size value");
        return 1;
    }
    if ((n > 10) || (n < 0))
    {
        printf("invalid size value");
        return 1;
    }
    for (i = 0; i < n; i++)
    {
        if (scanf("%lld", &a[i]) == 0)
        {
            printf("invalid element value");
            return 1;
        }
    }
    printf("%lld ", sum(a, n));
    return 0;
}
