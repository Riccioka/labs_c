#include <stdio.h>

#define N 10
#define M 10
#define SIZE 100
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

int mono(int a[N][M], int n, int m, int *b)
{
    int i, j, f, k;
    for (i = 0; i < n; i++)
    {
        f = 0;
        for (j = 0; j < m - 1; j++)
            if (f == 0)
            {
                if (a[i][j] > a[i][j + 1])
                    f = 2;
                if (a[i][j] < a[i][j + 1])
                    f = 1;
            }
            else
                break;
        k = 0;
        for (j = 0; j < m - 1; j++)
        {
            if ((a[i][j] >= a[i][j + 1] && f == 2) || (a[i][j] <= a[i][j + 1] && f == 1))
                k = 0;
            else
            {
                k = 1;
                break;
            }
        }
        if (k == 0 || f == 0)
            b[i] = 1;
        else
            b[i] = 0;
    }
    return 0;
}

void print_arr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

int main()
{
    int n = 0;
    int m = 0;
    int a[N][M];
    int b[SIZE];
    int i;

    if (read_mat(a, &n, &m))
        return INVALID_DATA;

    if (m == 1)
    {
        for (i = 0; i < n; i++)
            b[i] = 0;
        print_arr(&b[0], n);
        return 0;
    }

    mono(a, n, m, &b[0]);

    print_arr(&b[0], n);
    return 0;
}
