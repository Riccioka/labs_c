#include <stdio.h>
#include <malloc.h>

void print_in_file(FILE *f_out, int num, int **array)
{
    for (int i = 0; i < num; i++)
        fprintf(f_out, "%d ", *(*array+i));

    for (int i = 0; i < num; i++)
    {
        printf("%d ", *(*array+i));
    }
    printf("\n");

    free(*array);
}
