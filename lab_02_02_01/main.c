#include <stdio.h>

int isprime(long long n)
{
    if (n > 1)
    {
        for (int i = 2; i * i < n; i++)
            if (n % i == 0)
                return 1;
        return 0;
    }
    else
        return 1;
}

int main()
{
    int i, j;
    long long n;
    long long a[10];
    long long b[10];

    if (scanf("%lld", &n) <= 0 || n > 10 || n < 0)
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
    }
    j = 0;
    for (i = 0; i < n; i++)
    {
        if (isprime(a[i]) == 0)
            b[j++] = a[i];
    }
    for (i = 0; i < j; i++)
        printf("%lld ", b[i]);
    return 0;
}
