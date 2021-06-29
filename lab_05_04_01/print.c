#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include "struct.h"
#include "bad_size.h"

int print(char *file_src, char *file_dst, char *substr)
{
    FILE *fin = fopen(file_src, "rb");
    FILE *fout = fopen(file_dst, "wb");
    t_student s;
    int ret = -1;
    int rd = 0;
    int count = 0;

    memset(&s, 0, sizeof(s));
    if (fin && fout && !bad_size(fin))
    {
        ret = 0;
        while ((rd = fread(&s, sizeof(s), 1, fin)))
        {
            if (strstr(s.surname, substr) == s.surname)
            {
                fwrite(&s, sizeof(s), 1, fout);
                count++;
            }
        }
        if (!count)
            ret = -1;
    }
    if (fin)
        fclose(fin);
    if (fout)
        fclose(fout);
    return ret;
}
