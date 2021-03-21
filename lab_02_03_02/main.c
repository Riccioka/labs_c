#include <stdio.h>
#include <math.h>

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

int main()
{
    int j = 0;
    int n = 0;
    int a[10];
    int b[10];
    int k = 0;

    if (scanf("%d", &n) <= 0 || n > 10 || n < 0 || read_arr(&a[0], n))
        return 1;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] >= 0)
        {
            int temp = (int)sqrt(a[i]);
            if (temp * temp == a[i])
            {
                k += 1;
                continue;
            }
        }
        b[j++] = a[i];
    }
    if (k == n)
    {
        printf("error");
        return 1;
    }
    print_arr(&b[0], j);
    return 0;
}
