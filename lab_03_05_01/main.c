#include <stdio.h>
#include <stdlib.h>

#define N 10
#define M 10
#define SIZE 100
#define INVALID_ELEMENT_VALUE 1
#define INVALID_SIZES 1
#define INVALID_DATA -1
#define NUMBER_DOESNT_EXIST -2

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

void print_mat(int a[][10], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

int row_sum(int a[][M], int i, int j)
{
    int sum = 0;
    int safe = a[i][j];
    while (safe)
    {
        sum += abs(safe % 10);
        safe /= 10;
    }
    return sum;
}

void shift(int *b, int k)
{
    if (k == 2)
    {
        int safe = b[0];
        b[0] = b[1];
        b[1] = safe;
    }
    else if (k > 3)
    {
        int b0 = b[0];
        int b1 = b[1];
        int b2 = b[2];
        for (int i = 0; i < k - 3; i++)
            b[i] = b[i + 3];
        b[k - 1] = b2;
        b[k - 2] = b1;
        b[k - 3] = b0;
    }
}

int main()
{
    int n = 0, m = 0, k = 0, flag = 1;
    int a[N][M];
    int b[SIZE];

    if (read_mat(a, &n, &m))
        return INVALID_DATA;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (row_sum(a, i, j) > 10)
            {
                b[k] = a[i][j];
                k++;
                flag = 0;
            }
    if (flag)
        return NUMBER_DOESNT_EXIST;

    shift(&b[0], k);

    k = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (row_sum(a, i, j) > 10)
            {
                a[i][j] = b[k];
                k++;
            }

    print_mat(a, n, m);

    return 0;
}
