#include <stdio.h>
#include <stdio.h>
#include <limits.h>

int read_mat(int a[][20], int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (scanf("%d", &a[i][j]) != 1)
                return 1;
    return 0;
}


void print_mat(int a[][20], int n, int m)
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
    int a[20][20];

    int chet = 0;
    int nchet = 0;
    int kdop = 0;
    int i, j;

    if (scanf("%d", &n) <= 0 || n > 10 || n < 1 ||
        scanf("%d", &m) <= 0 || m > 10 || m < 1 ||
        read_mat(a, n, m))
        return -1;

    for (i = 0; i < n + kdop; i++)
    {
        chet = 0;
        nchet = 0;
        for (j = 0; j < m; j++)
        {
            int safe = a[i + kdop][j];
            int sum = 0;
            while (safe > 0)
            {
                sum += safe % 10;
                safe /= 10;
            }
            if (sum % 2 == 0)
                chet = 1;
            else
                nchet = 1;

            if (chet == 1 && nchet == 1)
            {
                for (int l = n + kdop; l > i; l--)
                    for (int q = 0; q < m; q++)
                        a[l][q] = a[l - 1][q];
                for (int q = 0; q < m; q++)
                    a[i + kdop][q] = -1;
                kdop++;
            }
        }
    }
    print_mat(a, n + kdop, m);
    return 0;
}

