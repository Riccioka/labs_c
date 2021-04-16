#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int read_mat1(int a[][10], int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (scanf("%d", &a[i][j]) != 1)
                return 1;
    return 0;
}


void print_mat1(int a[][10], int size, int m)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

int sum_digits(int n)
{
    int sum = 0;
    while (n)
    {
        sum += abs(n % 10);
        n /= 10;
    }
    return sum;
}

int main()
{
    int n = 0;
    int m = 0;
    int a[20][10];
    int nchet = 0;

    if (scanf("%d", &n) <= 0 || n > 10 || n < 1 ||
        scanf("%d", &m) <= 0 || m > 10 || m < 1 ||
        read_mat1(a, n, m))
        return -1;

    for (int i = 0; i < n; i++)
    {
        nchet = 0;

        for (int j = 0; j < m; j++)
            nchet += (sum_digits(a[i][j]) % 2);

        if (nchet > 1)
        {
            for (int j = 0; j < m; j++)
                printf("%d ", -1);
            printf("\n");
        }

        for (int j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}

