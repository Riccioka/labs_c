#include <stdio.h>
#include <math.h>
#include <limits.h>

int sum(int a, int *s)
{
    if (a % 2 == 0)
        *s += a;
    return *s;
}

int main()
{
    int i;
    int n;
    int a[10];
    int s = 0;
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
        sum(a[i], &s);
    }
    printf("%d ", s);
    return 0;
}
