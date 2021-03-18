#include <stdio.h>

int simple(int n)
{
    if (n > 1)
    {
        for (int i = 2; i < n; i++)
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
    }
    j = 0;
    for (i = 0; i < n; i++)     //копирование в массив b
    {
        if (simple(a[i]) == 0)
        {
            b[j] = a[i];
            j += 1;
        }
    }
    for (i = 0; i < j; i++)         //вывод массива b
        printf("%lld ", b[i]);
    return 0;
}
