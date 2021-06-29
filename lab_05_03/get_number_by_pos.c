#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_number_by_pos.h"
#include "put_number_by_pos.h"
#include "c.h"
#include "p.h"
#include "s.h"

int get_number_by_pos(FILE *fp, size_t ind)
{
    int num = 0;
//    size_t pos = ftell(fp);
    fseek(fp, ind * sizeof(int), SEEK_SET);
    fread(&num, sizeof(int), 1, fp);
//    fseek(fp, pos, SEEK_SET);
    return num;
}
