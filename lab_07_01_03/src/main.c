#include <string.h>

#include "errors.h"
#include "arr_and_file.h"
#include "key.h"
#include "mysort.h" // переделать с ключом -I

int main(int argc, char **argv)
{
    int er = 0;

    if (argc < 3 || argc > 4)
        er = INCORRECT_ARG_COUNT;

    FILE *in_file = NULL;
    if (!er)
    {
        in_file = fopen(argv[1], "r");
        if (in_file == NULL)
            er = FILE_NOT_FOUND;
        else
        {
            fseek(in_file, 0, SEEK_END);
            long pos = ftell(in_file);
            if (pos <= 0)
                er = READ_ERROR;
        }
    }

    size_t nums_in_file = 0;
    if (!er)
    {
        fseek(in_file, 0, 0);
        er = count_nums_in_file(in_file, &nums_in_file); //поиск кол-ва элементов
    }

    int *int_array = NULL;
    if (!er)
    {
        int_array = (int*)malloc(nums_in_file * sizeof(int));
        if (int_array == NULL)
            er = INIT_ERROR;
        else
            er = read_from_file_to_arr(in_file, int_array, int_array + nums_in_file);
    }

    int *new_arr_b = NULL;
    int *new_arr_e = NULL;
    if (!er)
        if (argc == 4)
        {
            if (strcmp(argv[3], "f") == 0)
                er = key(&(int_array[0]), &(int_array[0]) + nums_in_file, &new_arr_b, &new_arr_e);
            else
                er = INCORRECT_ARG;
        }

    if (!er)
    {
        FILE *out_file = fopen(argv[2], "w");

        if (out_file == NULL)
            er = FILE_NOT_FOUND;

        if (new_arr_b != NULL && new_arr_e != NULL)
        {
            int new_len = new_arr_e - new_arr_b;

            mysort(new_arr_b, new_len, sizeof(int), comparator); //сортировка по возрастанию
            write_array_to_file(out_file, new_arr_b, new_arr_e); //запись массива в файл
        }
        else
        {
            mysort(int_array, nums_in_file, sizeof(int), comparator);
            write_array_to_file(out_file, int_array, int_array + nums_in_file);
        }

        fclose(out_file);
    }

    if (in_file != NULL)
        fclose(in_file);

    if (int_array != NULL)
        free(int_array);
    if (new_arr_b != NULL)
        free(new_arr_b);

    return er;
}