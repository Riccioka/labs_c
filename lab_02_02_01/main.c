#include <stdio.h>

int read_arr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (scanf("%d", arr + i) <= 0)
        {
            printf("invalid element value");
            return 1;
        }
    }
    return 0;
}

void print_arr(int *arr, int size)
{
    for (int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
}

int isprime(int n)
{
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return 0;
    return (n > 1);
}

int main()
{
    int i, j;
    int n;
    int a[10];
    int b[10];
    int k = 0;

    if (scanf("%d", &n) <= 0 || n > 10 || n < 0 || read_arr(&a[0], n))
    {
        printf("invalid size value");
        return 1;
    }
    j = 0;
    for (i = 0; i < n; i++)
    {
        if (isprime(a[i]))
        {
            k = 1;
            b[j++] = a[i];
        }
    }
    if (k == 0)
    {
        printf("no one");
        return 1;
    }
    print_arr(&b[0], j);
    return 0;
}

