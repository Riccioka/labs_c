#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_number_by_pos.h"
#include "put_number_by_pos.h"
#include "c.h"
#include "p.h"
#include "s.h"

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
//    if (size % 4)
//        return -1;
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
