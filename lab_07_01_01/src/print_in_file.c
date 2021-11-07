#include <stdio.h>
#include <stdlib.h>

void print_in_file(FILE *f_out, int num, int **array)
{
    int i = 0;
    for (i = 0; i < num; i++)
        fprintf(f_out, "%d ", *(*array + i));
//    fprintf(f_out, "%d", *(*array + i));
}
