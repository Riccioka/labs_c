#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>

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

void fill_arr(long long *arr, int n)
{
    for (int i = 0; i < n; ++i)
        arr[i] = rand();
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

long long process_1(long long *arr, int n)
{
    long long item = 1;
    long long sum = 0;
    int i = 0;

    while (i < n)
    {
        item *= arr[i];
        sum += item;
        if (arr[i] < 0)
            return (sum);
        ++i;
    }
    return (sum);
}

long long process_2(long long *arr, int n)
{
    long long item = 1;
    long long sum = 0;
    int i = 0;

    while (i < n)
    {
        item *= *(arr + i); // arr[i]
        sum += item;
        if (*(arr + i) < 0)
            return (sum);
        ++i;
    }
    return (sum);
}

long long process_3(long long *beg, long long *end)
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
    struct timeval tv_start;
    struct timeval tv_end;
    long long duration = 0;
    long long n = 0;
    long long a[100000];
    const int count = 10;

    if (scanf("%lld", &n) <= 0)
        return 1;
    fill_arr(a, n);
    for (int i = 0; i < count; ++i)
    {
        gettimeofday(&tv_start, NULL);
        process_3(a, a + n);
        gettimeofday(&tv_end, NULL);
        duration += (tv_end.tv_sec - tv_start.tv_sec) * 1000000LL +
                    (tv_end.tv_usec - tv_start.tv_usec);
    }
    printf("%lld -> %lf", n, ((double)duration / count));
    return 0;
}
