//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include "../inc/print_in_file.h"
//#include "../inc/key.h"
//#include "../inc/mysort.h"
//#include "../inc/funcs.h"
//#define INCORRECT_INPUT -1
//#define NON_EXISTENT_FILE -2
//#define EMPTY_FILE -3
//#define EMPTY_NEW_ARR -4
//#define INITI_ERROR -5

//int main(int argc, char **argv)
//{

//    int *arr = NULL;
//    int count = 0, error = 0;
//    if (argc < 3 || argc > 4)
//        error = INCORRECT_INPUT;

//    FILE *f_in = NULL;

//    if (error == 0)
//    {
//        f_in = fopen(argv[1], "r");
//        if (f_in == NULL)
//            error = NON_EXISTENT_FILE;
//    }
//
//    if (error == 0)
//    {
//        error = count_nums_in_file(f_in, &count);

//        if (error == 0)
//        {
//            if (count < 1)
//                error = EMPTY_FILE;

//            if (error == 0)
//            {
//                rewind(f_in); // ?

//                arr = (int*)calloc(count, sizeof(int));
//                if (arr == NULL)
//                    error = INITI_ERROR;
//                else
//                    error = read_from_file_to_arr(f_in, arr, arr + count);
//                if (error == 0)
//                    error = check_uniq(arr, arr + count);

//                fclose(f_in);

//                setbuf(stdout, NULL);

//                if (error == 0)
//                {
//                    FILE *f_out = fopen(argv[2], "w");
//                    if (argc == 3)
//                    {
//                        mysort(arr, count, sizeof(int), comparator);
//    //                    if (f_out == NULL)
//    //                        error = NON_EXISTENT_FILE;
//                        write_array_to_file(f_out, arr, arr + count);
//                        fclose(f_out);
//                    }
//                    else if (argc == 4 && strcmp(argv[3], "f") == 0)
//                    {
//                        int *new_arr = NULL, *new_arr_end = NULL;
//                        int new_count = 0;

//                        if (count < 2)
//                            error = EMPTY_FILE;
//                        else
//                        {
//                            error = key(arr, arr + count, &new_arr, &new_arr_end);
//                            new_count = new_arr_end - new_arr;

//                            if (error == 0)
//                            {
//                                mysort(new_arr, new_count, sizeof(int), comparator);

//                                write_array_to_file(f_out, new_arr, new_arr + new_count);
////                                print_in_file(f_out, new_count, &new_arr);
//                                fclose(f_out);
//                            }

//                            if (new_arr != NULL)
//                                free(new_arr);
//                        }
//                    }
//                    else
//                        error = INCORRECT_INPUT;
//                }
//            }
//        }
//    }
//    if (arr != NULL)
//        free(arr);
//    if (f_in != NULL)
//        fclose(f_in);

//
//    return error;
//}



#include <string.h>

#include "../inc/funcs.h"
#include "../inc/key.h"
#include "../inc/mysort.h"

#define ONLY_ONE_NUM -10

int main(int argc, char **argv)
{
    int error_code = 0;
    if (argc < 3 || argc > 4)
        error_code = INCORRECT_ARG_COUNT;

    FILE *in_file = NULL;
    if (error_code == 0)
    {
        in_file = fopen(argv[1], "r");
        if (in_file == NULL)
            error_code = FILE_NOT_FOUND;
    }

    int nums_in_file = 0;
    if (error_code == 0)
    {
        error_code = count_nums_in_file(in_file, &nums_in_file);
        if (nums_in_file == 1)
            error_code = ONLY_ONE_NUM;
    }

    int *int_array = NULL;
    if (error_code == 0)
    {
        int_array = (int*)calloc(nums_in_file, sizeof(int));
        if (int_array == NULL)
            error_code = INIT_ERROR;
        else
            error_code = read_from_file_to_arr(in_file, int_array, int_array + nums_in_file);
        if (error_code == 0)
            error_code = check_uniq(int_array, int_array + nums_in_file);
    }

    int *new_arr_b = NULL;
    int *new_arr_e = NULL;
    if (error_code == 0)
    {
        if (argc == 4)
        {
            if (strcmp(argv[3], "f") == 0)
            {
                key(&(int_array[0]), &(int_array[0]) + nums_in_file, &new_arr_b, &new_arr_e);
            }
            else
                error_code = INCORRECT_ARG;
        }
    }

    if (error_code == 0)
    {
        FILE *out_file = fopen(argv[2], "w");
        if (new_arr_b != NULL && new_arr_e != NULL)
        {
            int new_len = 0;
            for (int *i = new_arr_b; i != new_arr_e; i++)
                new_len++;
            mysort(new_arr_b, new_len, sizeof(int), comparator);
            write_array_to_file(out_file, new_arr_b, new_arr_e);
        }
        else
        {
//            printf("\n");
            mysort(int_array, nums_in_file, sizeof(int), comparator);
            write_array_to_file(out_file, int_array, int_array + nums_in_file);
        }

        fclose(out_file);
    }
    if (in_file != NULL)
        fclose(in_file);

    return error_code;
}







//#include <string.h>

//#include "../inc/funcs.h"
//#include "../inc/key.h"
//#include "../inc/mysort.h"

//#define ONLY_ONE_NUM -10

//int main(int argc, char **argv)


//    int *int_array = NULL;
//    if (error_code == 0)
//    {
//        int_array = (int*)calloc(nums_in_file, sizeof(int));
//        if (int_array == NULL)
//            error_code = INIT_ERROR;
//        else
//            error_code = read_from_file_to_arr(in_file, int_array, int_array + nums_in_file);
//        if (error_code == 0)
//            error_code = check_uniq(int_array, int_array + nums_in_file);
//    }

//    int *new_arr_b = NULL;
//    int *new_arr_e = NULL;
//    if (error_code == 0)
//    {
//        if (argc == 4)
//        {
//            if (strcmp(argv[3], "f") == 0)
//            {
//                key(&(int_array[0]), &(int_array[0]) + nums_in_file, &new_arr_b, &new_arr_e);
//            }
//            else
//                error_code = INCORRECT_ARG;
//        }
//    }

//    if (error_code == 0)
//    {
//        FILE *out_file = fopen(argv[2], "w");
//        if (new_arr_b != NULL && new_arr_e != NULL)
//        {
//            int new_len = 0;
//            for (int *i = new_arr_b; i != new_arr_e; i++)
//                new_len++;
//            mysort(new_arr_b, new_len, sizeof(int), comparator);
//            write_array_to_file(out_file, new_arr_b, new_arr_e);
//        }
//        else
//        {
//            printf("\n");
//            mysort(int_array, nums_in_file, sizeof(int), comparator);
//            write_array_to_file(out_file, int_array, int_array + nums_in_file);
//        }

//        fclose(out_file);
//    }
//    if (in_file != NULL)
//        fclose(in_file);

//    return error_code;
//}



