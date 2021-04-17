#include <stdio.h>

void print_mat(int a[][10], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

void odd(int a[][10], int n, int m, int j)
{
    for (int i = 0; i < n; i++)
        a[i][j] = n * m - j * n - i;
}

void even(int a[][10], int n, int m, int j)
{
    for (int i = n; i >= 0; i--)
        a[i][j] = n * m - j * n - (n - 1 - i);
}

int main()
{
    int n = 0;
    int m = 0;
    int a[10][10];

    if (scanf("%d", &n) <= 0 ||
        n > 10 || n < 1 ||
        scanf("%d", &m) <= 0 ||
        m > 10 || m < 1)
        return -1;

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
