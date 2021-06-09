#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 20
#define M 20
#define INVALID_ELEMENT_VALUE 1
#define INVALID_SIZES 1
#define INVALID_DATA -1

int read_mat(int a[][M], int *n, int *m)
{
    if (scanf("%d", n) <= 0 || *n > 10 || *n < 1 ||
            scanf("%d", m) <= 0 || *m > 10 || *m < 1)
        return INVALID_SIZES;
    for (int i = 0; i < *n; i++)
        for (int j = 0; j < *m; j++)
            if (scanf("%d", &a[i][j]) != 1)
                return INVALID_ELEMENT_VALUE;
    return 0;
}


void print_mat(int a[][M], int size, int m)
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

void dop_str(int a[][M], int n, int m, int start)
{
    for (int i = n + 1; i > start; i--)
        for (int j = 0; j < m; j++)
            a[i][j] = a[i - 1][j];
    for (int j = 0; j < m; j++)
        a[start][j] = -1;
}

int main()
{
    int n = 0, m = 0, nchet = 0, i = 0;
    int a[N][M];

    if (read_mat(a, &n, &m))
        return INVALID_DATA;

    int size = n;

    while (i != n)
    {
        nchet = 0;
        for (int j = 0; j < m; j++)
            nchet += (sum_digits(a[i + size - n][j]) % 2);
        if (nchet > 1)
        {
            dop_str(a, n + size, m, i + size - n);
            size++;
        }
        i++;
    }
    print_mat(a, size, m);

    return 0;
}

