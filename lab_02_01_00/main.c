#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int sum(int a, int *s)
{
    if (a % 2 == 0)
        *s += a;
    return *s;
}

int main()
{
    int n, i;
    int a[10];
    int s = 0;
    int k = 0;
    if (scanf("%d", &n) != 1 || n > 10 || n <= 0)
    {
        printf("invalid size value");
        return 1;
    }
    for (i = 0; i < n; i++)
    {
        if (scanf("%d", &a[i]) <= 0)
        {
            printf("invalid element value");
            return 1;
        }
        if (abs(a[i]) + s > INT_MAX)
        {
            printf("invalid element value");
            return 1;
        }
        if (s != sum(a[i], &s))
            k = 1;
    }
    if (k == 1)
    {
        printf("no one");
        return 1;
    }
    printf("%d ", s);
    return 0;
}
