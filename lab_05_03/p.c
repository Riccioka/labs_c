#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int p(char *fname)
{
    FILE *fp = fopen(fname, "rb");
    int n = 0;

    if (!fp)
        return -1;
    while (!feof(fp))
    {
        if (fread(&n, sizeof(n), 1, fp) != 1)
            return -1;
        printf("%d ", n);
    }
    fclose(fp);
    return 0;
}
