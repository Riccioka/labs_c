#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool failflag = false;

int get_number_by_pos(FILE *fp, int pos)
{
    int n = 0;
    fseek(fp, pos * sizeof(n), SEEK_SET);
    if (!feof(fp)) failflag = (fread(&n, sizeof(n), 1, fp) == 0); else failflag = true;
    return n;
}

int put_number_by_pos(FILE *fp, int pos, int n)
{
    fseek(fp, pos * sizeof(n), SEEK_SET);
    return fwrite(&n, sizeof(n), 1, fp);
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
        if (put_number_by_pos(fp, i, n) != 1)
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


int s(char *fname)
{
    FILE *fp = fopen(fname, "r+b");
    if (!fp)
        return -1;
    int n, m;
    int i = 0;
    int j = 0;
    while (!feof(fp))
    {
        failflag = false;
        n = get_number_by_pos(fp, i);
        if (!failflag)
        {
            j = i;
            while (!feof(fp))
            {
                j++;
                failflag = false;
                m = get_number_by_pos(fp, j);
                if (!failflag)
                {
                    if (m < n)
                    {
                        put_number_by_pos(fp, j, n);
                        put_number_by_pos(fp, i, m);
                        break;
                    }
                }
                else break;
            }
            i++;
        }
        else break;
    }
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
