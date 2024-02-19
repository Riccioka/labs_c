#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

#define OK 0
#define FILE_ERROR -1
#define SIZE_ERROR -2
#define MEMORY_ERROR -3
#define NONE_MIN -4

int main (int argc, char **argv)
{
    int rc = OK;
    if (argc !=2)
    {
        rc = -1;
        return rc;
    }

    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
        return FILE_ERROR;

    int n, m;
    if (fscanf(f, "%d %d", &n, &m) != 2)
    {
        fclose(f);
        return SIZE_ERROR;
    }
    if (n <= 0 || m <= 0 || n != m)
    {
        fclose(f);
        return SIZE_ERROR;
    }

    int **mtr = alloc_mtr(n, m);
    if(mtr == NULL)
    {
        fclose(f);
        return MEMORY_ERROR;
    }

    rc = read_mtr(f, mtr, n, m);
    if (rc != 0)
    {
        fclose(f);
        return FILE_ERROR;
    }

    int min = find_min(mtr, n, m);
    if (min == 2)
        return NONE_MIN;
       // printf("none");
    else
        printf("min = %d", min);

    mtr_free(mtr, n);
    fclose(f);
    return rc;
}
