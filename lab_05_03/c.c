#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_number_by_pos.h"
#include "put_number_by_pos.h"
#include "c.h"
#include "p.h"
#include "s.h"

int c(char *fname, int num)
{
    FILE *fp = fopen(fname, "wb");
    int n = 0;

    if (!fp)
        return -1;
    for (int i = 0; i < num; ++i)
    {
        n = rand();
        printf("%d ", n);
        if (put_number_by_pos(fp, i, n) != 1)
            return -1;
    }
    fclose(fp);
    return 0;
}
