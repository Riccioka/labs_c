#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../inc/funcs.h"
#define INCORRECT_INPUT -1

int count_nums_in_file(FILE *in_file, int *nums_in_file)
{
    int read_code = 0;
    int nums_read = 0;
    int cur_num = 0;
    long pos = 0;

    fseek(in_file, 0, SEEK_END);
    pos = ftell(in_file);
    if (pos <= 0)
        return INCORRECT_INPUT;
    fseek(in_file, 0, SEEK_SET);

    while ((read_code = fscanf(in_file, "%d", &cur_num)) != EOF)
    {
        if (read_code == 1)
            nums_read++;
        else if (read_code == 0)
            return INCORRECT_INPUT;
    }

    if (nums_read == 0 && read_code == EOF)
        return INCORRECT_INPUT;

    *nums_in_file = nums_read;
    fseek(in_file, 0L, SEEK_SET);

    if (nums_read == 1)
        return INCORRECT_INPUT;
    return 0;
}

int get_elements(FILE *in_file)
{
    int error = 0, num = 0;
    while (fscanf(in_file, "%d", &num))
        num++;
    if (feof(in_file) && num != 0)
        error = num;
    else
        error = INCORRECT_INPUT;
    return error;
}

int read_array(char *filename, int **arr, int **end_arr)
{
    int error = 0;
    FILE *in_file = fopen(filename, "r");
    if (in_file == NULL)
        return INCORRECT_INPUT;
    error = get_elements(in_file);

    rewind(in_file);

    if (error >= 1)
    {
        int n = error;
        error = 0;
        *arr = malloc(n * sizeof(int));
        *(end_arr) = *arr + n;
        if (*arr == NULL)
            error = INCORRECT_INPUT;
        else
            for (int *ptr = *arr; ptr != *end_arr; ptr++)
                fscanf(in_file, "%d", ptr);
    }
    fclose(in_file);
    return error;
}

int read_from_file_to_arr(FILE *in_file, int *pb, int *pe)
{
    while (pb != pe)
    {
        if (fscanf(in_file, "%d", pb) != 1)
            return INCORRECT_INPUT;
        ++pb;
    }
    return 0;
}


int check_uniq(int *pb, int *pe)
{
    int same_flag = 0;

    while (pb != pe && same_flag == 0)
    {
        int *cur_iter = pb;

        while (cur_iter != pe && !same_flag)
        {
            if (cur_iter != pb && *cur_iter == *pb)
                same_flag = 1;
            cur_iter++;
        }
        ++pb;
    }

    return -same_flag;
}


int write_array_to_file(FILE *out_file, int *pb, int *pe)
{
    if (!out_file)
        return INCORRECT_FILE_POINTER;

    while (pb != pe)
    {
        fprintf(out_file, "%d", *pb);
        ++pb;
        if (pb != pe)
            fprintf(out_file, "%c", '\n');
    }

    return 0;
}
