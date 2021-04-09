#include <stdio.h>

int read_mat(int a[][10], int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (scanf("%d", &a[i][j]) != 1)
                return 1;
    return 0;
}

void print_mat(int a[][10], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d", a[i][j]);
        printf("\n");
    }
}

int isprime(int n)
{
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return 0;
    return (n > 1);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_rows(int a[][10], int m, int i, int j)
{
    for (int k = 0; k < m; k++)
        swap(&a[i][k], &a[j][k]);
}

void task3(int a[10][10], int n, int m)
{
    int b[10];

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
            sum += a[i][j];
        b[i] = sum;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (b[i] > b[j])
            {
                swap(&b[i], &b[j]);
                swap_rows(a, m, i, j);
            }
        }
    }
}

int main()
{
    int n = 0;
    int m = 0;

    int a[10][10];

    if (scanf("%d", &n) <= 0 ||
        n > 10 || n < 1 ||
        scanf("%d", &m) <= 0 ||
        m > 10 || m < 2 ||
        read_mat(a, n, m))
        return -1;

    task3(a, n, m);

    print_mat(a, n, m);

    return 0;
}
