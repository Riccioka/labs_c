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

int main()
{
    int n = 0;
    int m = 0;

    int a[10][10];

    if (scanf("%d", &n) <= 0 || n > 10 || n < 3 ||
        scanf("%d", &m) <= 0 || m > 10 || m < 3 ||
        read_mat(a, n, m))
        return -1;

    int flag = 1;
    int min = INT_MAX;

    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if ((a[i][j] < min || flag) && a[i][j] % 2 == 1)
            {
                min = a[i][j];
                flag = 0;
            }
    if (flag)
        return 1;
    printf("%d", min);
    return 0;
}

