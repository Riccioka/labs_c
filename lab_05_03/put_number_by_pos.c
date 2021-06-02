#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void put_number_by_pos(FILE *fp, size_t ind, int num)
{
    size_t pos = ftell(fp);
    fseek(fp, ind * sizeof(int), SEEK_SET);
    fwrite(&num, sizeof(int), 1, fp);
    fseek(fp, pos, SEEK_SET);
}
