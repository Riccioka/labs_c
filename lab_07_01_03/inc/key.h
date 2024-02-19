#ifndef _KEY_H_
#define _KEY_H_

#include <stdlib.h>

int new_len(int *arr, int *arr_end);

int copy_elements(int *arr, int **new_arr, int **new_arr_end, int new_count);

int key(int *pb_arr, int *pe_arr, int **pb_new_arr, int **pe_new_arr); //фильтрация элементов до последнего отрицательного
                                                               // из массива *pb_arr в массив **pb_new_arr

#endif
