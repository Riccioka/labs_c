#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include "struct.h"

int bad_size(FILE *fp)
{
    fseek(fp, 0, SEEK_END);
    size_t size_file = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    return (size_file % sizeof(t_student));
}

double get_average(FILE *fin)
{
    double average = 0;
    size_t count = 0;
    t_student s;

    memset(&s, 0, sizeof(s));
    if (!fin)
        return 0;
    while (fread(&s, sizeof(s), 1, fin))
    {
        average += s.a[0] + s.a[1] + s.a[2] + s.a[3];
        count += 4;
    }
    return count ? (average / count) : 0;
}

int del(char *args)
{
    FILE *fin = fopen(args, "r+b");
    double average = get_average(fin);
    t_student s;
    int ret = -1;
    int rd = 0;
    size_t offset = 0;
    size_t current_pos = 0;

    memset(&s, 0, sizeof(s));
    if (fin && !bad_size(fin))
    {
        fseek(fin, 0, SEEK_SET);
        ret = 0;
        while ((rd = fread(&s, sizeof(s), 1, fin)))
        {
            if ((s.a[0] + s.a[1] + s.a[2] + s.a[3]) / 4.0 >= average)
            {
                current_pos = ftell(fin);
                fseek(fin, offset, SEEK_SET);
                fwrite(&s, sizeof(s), 1, fin);
                offset += sizeof(s);
                fseek(fin, current_pos, SEEK_SET);
            }
        }
    }
    if (fin)
    {
        fclose(fin);
        truncate(args, offset);
    }
    return ret;
}
