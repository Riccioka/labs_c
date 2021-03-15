#include <stdio.h>

int sum(int *a, int n)
{
    int s = 0;
    int i;
    for (i = 0; i < n; i++)
        if (a[i] % 2 == 0)
            s += a[i];
    return s;
}

int main()
{
    int i, n;
    int a[10];
    if (scanf("%d", &n) == 0)
        return 1;
    if (n > 10)
        return 1;
    for (i = 0; i < n; i++)
    {
        if (scanf("%d", &a[i]) == 0)
        {
            printf("Error");
            return 1;
        }
    }
    printf("%d ", sum(a, n));
    return 0;
}
