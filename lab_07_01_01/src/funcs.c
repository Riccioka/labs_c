#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../inc/funcs.h"
#define INCORRECT_INPUT -1

int count_nums_in_file(FILE *in_file, int *nums_in_file)
{
    int read_code = 0;
    int error = 0;

    int nums_read = 0;
    int cur_num;

    fseek(in_file, 0, SEEK_END);
    long pos = ftell(in_file);
    if (pos <= 0)
        error = INCORRECT_INPUT;
    fseek(in_file, 0, 0);

    while ((read_code = fscanf(in_file, "%d", &cur_num)) != EOF && error == 0)
    {
        if (error == 0)
        {
            if (read_code == 1)
                nums_read++;
            else if (read_code == 0)
                error = INCORRECT_INPUT;
        }
    }

    if (nums_read == 0 && error == EOF)
        error = INCORRECT_INPUT;

    if (error == 0)
        *nums_in_file = nums_read;

    fseek(in_file, 0L, SEEK_SET);

    return error;
}

int read_from_file_to_arr(FILE *in_file, int *pb, int *pe)
{
    int error = 0;
    int cur_num;
    for (int *i = pb; i != pe; i++)
    {
        if (error == 0)
        {
            if (fscanf(in_file, "%d", &cur_num) != 1)
                error = INCORRECT_INPUT;
            if (error == 0)
                *i = cur_num;
        }
    }

    return error;
}


int check_uniq(int *pb, int *pe)
{
    int *cur_elem = pb;
    int same_flag = 0;
    while (cur_elem != pe && same_flag == 0)
    {
        int *cur_iter = pb;
        while (cur_iter != pe && same_flag == 0)
        {
            if (cur_iter != cur_elem && *cur_iter == *cur_elem)
                same_flag = 1;
            cur_iter++;
        }

        cur_elem++;
    }
    if (same_flag == 1)
        return -1;
    else
        return 0;
}


int write_array_to_file(FILE *out_file, int *pb, int *pe)
{
    int error_code = 0;

    if (out_file == NULL)
        error_code = INCORRECT_FILE_POINTER;

    if (error_code == 0)
        for (int *i = pb; i != pe; i++)
        {
            fprintf(out_file, "%d", *i);
            if ((i + 1) != pe)
                fprintf(out_file, "%c", '\n');
        }

    return error_code;
}
