#include <stdio.h>

int check(int a)
{
    if ()
        return 0;
    else
        return 1;
}

int main()
{
    int i, j;
    long long n;
    long long a[10];
    if (scanf("%lld", &n) <= 0)       // проверка на ввод n
    {
        printf("invalid size value");
        return 1;
    }
    if ((n > 10) || (n < 0))
    {
        printf("invalid size value");
        return 1;
    }
    for (i = 0; i < n; i++)     //ввод массива а
    {
        if (scanf("%lld", &a[i]) <= 0)
        {
            printf("invalid element value");
            return 1;
        }
        if (check(a[i]) == 0)
            for j in range(i; i < n - 1; i++)
                a[i] = a[i + 1]
    }
