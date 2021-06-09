#include <stdio.h>
#include <limits.h>

#define N 10
#define M 10
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


void print_mat(int a[][M], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

int search_min(int a[][M], int n)
{
    int flag = 1;
    int min = INT_MAX;

    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if ((a[i][j] < min || flag) && a[i][j] % 2)
            {
                min = a[i][j];
                flag = 0;
            }
    if (flag)
        return NUMBER_DOESNT_EXIST;
    return min;
}

int main()
{
    int n = 0;
    int m = 0;

    int a[N][M];

    if (read_mat(a, &n, &m))
        return INVALID_DATA;

    if (search_min(a, n) == NUMBER_DOESNT_EXIST)
        return NUMBER_DOESNT_EXIST;
    printf("%d", search_min(a, n));
    return 0;
}

