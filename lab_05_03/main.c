#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_number_by_pos(FILE *fp, size_t ind)
{
    int num = 0;
    size_t pos = ftell(fp);
    fseek(fp, ind * sizeof(int), SEEK_SET);
    fread(&num, sizeof(int), 1, fp);
    fseek(fp, pos, SEEK_SET);
    return num;
}

void put_number_by_pos(FILE *fp, size_t ind, int num)
{
    size_t pos = ftell(fp);
    fseek(fp, ind * sizeof(int), SEEK_SET);
    fwrite(&num, sizeof(int), 1, fp);
    fseek(fp, pos, SEEK_SET);
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
    size_t size = 0;
    size_t count = 0;

    if (!fp)
        return -1;
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    if (size % 4)
        return -1;
    count = size / 4;
    for (size_t i = 0; i < count; ++i)
    {
        for (size_t j = 0; j < count; ++j)
        {
            int n1 = get_number_by_pos(fp, i);
            int n2 = get_number_by_pos(fp, j);
            if (n1 < n2)
            {
                put_number_by_pos(fp, j, n1);
                put_number_by_pos(fp, i, n2);
            }
        }
    }
    fclose(fp);
    return 0;
}

int main(int argc, char **argv)
{
    if (argc > 4 || argc < 3 || strlen(argv[1]) != 1)
        return -1;
    if (argc == 4 && argv[1][0] == 'c')
        return c(argv[argc - 1], atoi(argv[2]));
    else if (argv[1][0] == 'p')
        return p(argv[argc - 1]);
    else if (argv[1][0] == 's')
        return s(argv[argc - 1]);
    return -1;
}
