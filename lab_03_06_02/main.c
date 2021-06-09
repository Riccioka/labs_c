#include <stdio.h>

#define N 10
#define M 10
#define INVALID_SIZES 1
#define NUMBER_DOESNT_EXIST -2

int read_size(int *n, int *m)
{
    if (scanf("%d", n) <= 0 || *n > 10 || *n < 1 ||
        scanf("%d", m) <= 0 || *m > 10 || *m < 1)
        return INVALID_SIZES;
    return 0;
}

void print_mat(int a[][M], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

void odd(int a[][M], int n, int m, int j)
{
    for (int i = 0; i < n; i++)
        a[i][j] = n * m - j * n - i;
}

void even(int a[][M], int n, int m, int j)
{
    for (int i = n; i >= 0; i--)
        a[i][j] = n * m - j * n - (n - 1 - i);
}

int main()
{
    int n = 0;
    int m = 0;
    int a[N][M];

    if (read_size(&n, &m))
        return INVALID_SIZES;

    for (int j = 0; j < m; j++)
    {
        if (j % 2)
            odd(a, n, m, j);
        else
            even(a, n, m, j);;
    }

    print_mat(a, n, m);

    return 0;
}
