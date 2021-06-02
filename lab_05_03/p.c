#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool failflag = false;

int p(char *fname)
{
    FILE *fp = fopen(fname, "rb");
    int n = 0;

    if (!fp)
        return -1;
    int i = 0;
    while (!feof(fp))
    {
        failflag = false;
        n = get_number_by_pos(fp, i);
        if (!failflag) printf("%d ", n);
        i++;
    }
    fclose(fp);
    return 0;
}
