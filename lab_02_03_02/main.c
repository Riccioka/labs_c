#include <stdio.h>
#include <math.h>

int read_arr(long long *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (scanf("%lld", arr + i) <= 0)
        {
            printf("invalid element value");
            return 1;
        }
    }
    return 0;
}

void print_arr(long long *arr, int size)
{
    for (int i = 0; i < size; ++i)
        printf("%lld ", arr[i]);
}

int main()
{
    int j = 0;
    long long n = 0;
    long long a[10];
    long long b[10];

    if (scanf("%lld", &n) <= 0 || n > 10 || n < 0 || read_arr(&a[0], n))
        return 1;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] >= 0)
        {
            int temp = (int)sqrt(a[i]);
            if (temp * temp == a[i])
                continue;
        }
        b[j++] = a[i];
    }
    print_arr(&b[0], j);
    return 0;
}
