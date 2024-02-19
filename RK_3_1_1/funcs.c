#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

void mtr_free(int **mtr, int n)
{
    for (int i = 0; i < n; i++)
        free(mtr[i]);
    free(mtr);
}


int **alloc_mtr(int n, int m)
{
    int **data = calloc(n, sizeof(int *));
    if (!data)
        return NULL;
    for (int i = 0; i < n; i++)
    {
        data[i] = malloc(m * sizeof (int));
        if (!data[i])
        {
            mtr_free(data, i);
            return NULL;
        }
    }

    return data;
}

int read_mtr(FILE *f, int **mtr, int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (fscanf(f, "%d", &mtr[i][j]) != 1)
                return -1;
        }

    return 0;
}

int find_min(int **mtr, int n, int m)
{
    int min = 2;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
        {
//            printf("%d ", mtr[i][j]);
            if (((abs(mtr[i][j]) % 2) == 1) && (mtr[i][j] < min || min == 2)) //
                min = mtr[i][j];
        }
    return min;
}
