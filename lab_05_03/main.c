#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_number_by_pos(FILE *fp, pos)
{

}

void put_number_by_pos(FILE *fp, )
{

}

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
        if (fwrite(&n, sizeof(n), 1, fp) != 1)
            return -1;
    }
    fclose(fp);
    return 0;
}


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


int s(char *fname)
{
    FILE *fp = fopen(fname, "r+b");
    if (!fp)
        return -1;

    fclose(fp);
    return 0;
}


int main(int argc, char **argv)
{
    if (argc < 3 || strlen(argv[1]) != 1)
        return -1;
    if (argv[1][0] == 'c')
        return c(argv[argc - 1], atoi(argv[2]));
    else if (argv[1][0] == 'p')
        return p(argv[argc - 1]);
    else if (argv[1][0] == 's')
        return s(argv[argc - 1]);
    return -1;
}
