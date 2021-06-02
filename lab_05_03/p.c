#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int p(char *fname)
{
    FILE *fp = fopen(fname, "rb");
    size_t size = 0;
    int n = 0;

    if (!fp)
        return -1;

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    if (size % 4)
        return -1;
    while (fread(&n, sizeof(n), 1, fp) == 1)
        printf("%d\n", n);
    fclose(fp);
    return 0;
}
