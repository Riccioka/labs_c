#include <stdio.h>
#include <limits.h>

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

int row_sum(int a[10][10], int m, int i)
{
    int sum = 0;

    for (int j = 0; j < m; ++j)
        sum += a[i][j];
    return sum;
}

void shift(int *b, int k)
{
    b[k - 3] = b[0];
    b[k - 2] = b[1];
    b[k - 1] = b[2];
    for (int i = 0; i < k - 3; i++)
        b[i] = b[i + 3];
}

int main()
{
    int n = 0;
    int m = 0;
    int k = 0;
    int flag = 1;
    int a[10][10];
    int b[100];

    if (scanf("%d", &n) <= 0 ||
        n > 10 || n < 1 ||
        scanf("%d", &m) <= 0 ||
        m > 10 || m < 1 ||
        read_mat(a, n, m))
        return -1;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (row_sum(a, m, i) > 10)
            {
                b[k] = a[i][j];
                k++;
                flag = 0;
            }
    if (flag)
        return -1;
    shift(&b[0], k);

    print_mat(a, n, m);

    return 0;
}
