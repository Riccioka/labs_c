#include <stdio.h>


int read_arr(int a[10][10], int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (scanf("%d", &a[i][j]) <= 0)
            {
                printf("invalid element value");
                return 1;
            }
    return 0;
}

void print_arr(int *arr, int size)
{
    for (int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
}

//int search(a)
//    int f = 0;
//    for (j = 0; j < m - 1; j++)
//        if (f == 0)
//        {
//            if (a[i][j] > a[i][j + 1])
//                f = 2;
//            if (a[i][j] < a[i][j + 1])
//                f = 1;
//        }
//    return f;

int main()
{
    int n = 0;
    int m = 0;
    int a[10][10];
    int b[100];
    int i, j, f, k;

    if (scanf("%d", &n) <= 0 || n > 10 || n < 0 || scanf("%d", &m) <= 0 || m > 10 || m < 0 || read_arr(a, n, m))
        return 1;

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
        k = 0;
        for (j = 0; j < m - 1; j++)
        {
            if ((a[i][j] >= a[i][j + 1] && f == 2) || (a[i][j] <= a[i][j + 1] && f == 1))
                b[i * j + j] = a[i][j];
            else
                k = 1;
        }
        if (k == 0)
            b[i * m + m - 1] = a[i][m - 1];
        if (f == 0)
            for (j = 0; j < m; j++)
                b[i * j + j] = a[i][j];
    }
    print_arr(&b[0], j);
    return 0;
}
