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
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

void swap_rows(int a[][10], int m, int i, int j)
{
    for (int k = 0; k < m; k++)
    {
        int temp = a[i][k];
        a[i][k] = a[j][k];
        a[j][k] = temp;
    }
//        swap(&a[i][k], &a[j][k]);
}

int row_sum(int a[10][10], int n, int m, int i)
{
    int sum = 0;

    for (int j = 0; j < m; ++j)
        sum += a[i][j];
    return sum;
}

int main()
{
    int n = 0;
    int m = 0;
    int b[10];
    int a[10][10];

    if (scanf("%d", &n) <= 0 ||
        n > 10 || n < 1 ||
        scanf("%d", &m) <= 0 ||
        m > 10 || m < 1 ||
        read_mat(a, n, m))
        return -1;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (row_sum(a, n, m, i) < row_sum(a, n, m, j))
                swap_rows(a, m, i, j);

    print_mat(a, n, m);

    return 0;
}
