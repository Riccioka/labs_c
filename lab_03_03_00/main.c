#include <stdio.h>
#include <limits.h>

#define N 10
#define M 10
#define INVALID_ELEMENT_VALUE 1
#define INVALID_SIZES 1
#define INVALID_DATA -1


int read_mat(int a[][M], int n, int m)
{
    if (scanf("%d", &n) <= 0 || n > 10 || n < 1 ||
            scanf("%d", &m) <= 0 || m > 10 || m < 1)
        return INVALID_SIZES;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (scanf("%d", &a[i][j]) != 1)
                return INVALID_ELEMENT_VALUE;
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

int row_sum(int a[10][10], int m, int i)
{
    int sum = 0;

    for (int j = 0; j < m; ++j)
        sum += a[i][j];
    return sum;
}

int main(void)
{
    int n = 0;
    int m = 0;
    int a[N][M] = { 0 };

    if (read_mat(a, n, m))
        return INVALID_DATA;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (row_sum(a, m, i) < row_sum(a, m, j))
                swap_rows(a, m, i, j);

    print_mat(a, n, m);
    return 0;
}

