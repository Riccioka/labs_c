#include "arr_and_file.h"
#include "errors.h"

int count_nums_in_file(FILE *in_file, size_t *nums_in_file)
{
    int read_code = 0, er = 0;
    size_t nums_read = 0;
    int cur_num;

    while ((read_code = fscanf(in_file, "%d", &cur_num)) != EOF && er == 0)
        if (!er)
        {
            if (read_code == 1)
                nums_read++;
            else if (read_code == 0)
                er = READ_ERROR;
        }

    if (nums_read == 0 && er == EOF)
        er = READ_ERROR;

    if (!er)
        *nums_in_file = nums_read;
    fseek(in_file, 0L, SEEK_SET);

    return er;
}

int read_from_file_to_arr(FILE *in_file, int *pb, int *pe)
{
    int er = 0;
    int cur_num;
    for (int *el = pb; el != pe; el++)
        if (!er)
        {
            if (fscanf(in_file, "%d", &cur_num) != 1)
                er = READ_ERROR;
            else
                *el = cur_num;
        }
    return er;
}

int write_array_to_file(FILE *out_file, int *pb, int *pe)
{
    int er = 0;

    if (out_file == NULL)
        er = INCORRECT_FILE_POINTER;
    else
        for (int *el = pb; el != pe; el++)
            fprintf(out_file, "%d ", *el);

    return er;
}
