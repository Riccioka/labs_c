#include <stdio.h>
#include <math.h>

int read_arr(long long *arr, int size)
{
    for (int i = 0; i < size; i++)
        if (scanf("%lld", arr + i) <= 0)
            return (i);
    return (size);
}

void print_arr(long long *arr, int size)
{
    for (int i = 0; i < size; ++i)
        printf("%lld ", arr[i]);
}

void swap(long long *a, long long *b)
{
    long long t = *a;
    *a = *b;
    *b = t;
}

long long spec_sum(long long *beg, long long *end)
{
    long long item = 1;
    long long sum = 0;

    while (beg != end)
    {
        item *= *beg;
        sum += item;
        if (*beg < 0)
            return (sum);
        ++beg;
    }
    return (sum);
}

int main(void)
{
    const int size = 10;
    long long n = 0;
    long long a[10];

    n = read_arr(&a[0], size);
    printf("%lld", spec_sum(a, a + n));

    return 0;
}
