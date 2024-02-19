#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int new_len(int *arr, int *arr_end)
{
    int count = arr_end - arr;
    int start = 0, end = count;
    int *el;

    for (int i = 0; i < count; i++)
    {
        el = arr + i;
        if (*el < 0)
            end = i;
    }

    return end - start;
}

int copy_elements(int *arr, int **new_arr, int **new_arr_end, int new_count)
{
    int er = 0;
    int *new_el;
    int *el;

    *new_arr_end = *new_arr + new_count;
    for (int i = 0; i < new_count; i++)
    {
        new_el = *new_arr + i;
        el = arr + i;
        *new_el = *el;  //*(*new_arr + i) = *(arr + i);
    }
    if (new_arr == new_arr_end)
        er = -1;

    return er;
}


int key(int *arr, int *arr_end, int **new_arr, int **new_arr_end)
{
    int er = 0;
    if (new_arr == NULL || new_arr_end == NULL || arr == NULL || arr_end == NULL || arr >= arr_end)
        return -1;

    int new_count = new_len(arr, arr_end);
    if (new_count <= 0)
        er = -1;

    if (!er)
    {
        *new_arr = (int *) malloc(new_count * sizeof(int));
        if (new_arr == NULL)
            er = -1;
        else
            er = copy_elements(arr, new_arr, new_arr_end, new_count);
    }

    return er;
}