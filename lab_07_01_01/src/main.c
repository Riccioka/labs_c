#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../inc/print_in_file.h"
#include "../inc/key.h"
#include "../inc/mysort.h"
#include "../inc/funcs.h"
#define INCORRECT_INPUT -1
#define NON_EXISTENT_FILE -2
#define EMPTY_FILE -3
#define EMPTY_NEW_ARR -4
#define INITI_ERROR -5

int main(int argc, char **argv)
{
    int *arr = NULL, *end_arr = NULL;
    int count = 0, error = 0;
    if (argc < 3 || argc > 4)
        error = INCORRECT_INPUT;

    printf("%d ", error);

    error = read_array(argv[1], &arr, &end_arr);

    printf("%d ", error);

    setbuf(stdout, NULL);

    if (error == 0)
    {
        FILE *f_out = fopen(argv[2], "w");
        if (argc == 3)
        {
            mysort(arr, count, sizeof(int), comparator);

            write_array_to_file(f_out, arr, arr + count);
            fclose(f_out);
        }
        else if (argc == 4 && strcmp(argv[3], "f") == 0)
        {
            int *new_arr = NULL, *new_arr_end = NULL;
            int new_count = 0;

            if (count < 2)
                error = EMPTY_FILE;
            else
            {
                error = key(arr, arr + count, &new_arr, &new_arr_end);
                new_count = new_arr_end - new_arr;

                if (error == 0)
                {
                    mysort(new_arr, new_count, sizeof(int), comparator);

                    write_array_to_file(f_out, new_arr, new_arr + new_count);
//                                print_in_file(f_out, new_count, &new_arr);
                    fclose(f_out);
                }

                if (new_arr != NULL)
                    free(new_arr);
            }
        }
        else
            error = INCORRECT_INPUT;
    }
    if (arr != NULL)
        free(arr);

    printf("%d", error);
    return error;
}
