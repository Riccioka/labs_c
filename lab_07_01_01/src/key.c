#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int key(int *arr, int *arr_end, int **new_arr, int **new_arr_end)
{
    int error = 0;
    if (new_arr == NULL || new_arr_end == NULL || arr == NULL || arr_end == NULL || arr >= arr_end)
        error = -1;

    if (error == 0)
    {
        int start = 0, end = 0;
        int min = *arr, max = *arr;
        int count = arr_end - arr;

        for (int i = 1; i < count; i++)
        {
            if (*(arr + i) > max)
            {
                max = *(arr + i);
                end = i;
            }
            if (*(arr + i) < min)
            {
                min = *(arr + i);
                start = i;
            }
        }

        if (end < start)
        {
            int time = end;
            end = start;
            start = time;
        }

        int new_count = end - start - 1;

        if (new_count <= 0)
            error = -1;

        if (error == 0)
        {
            *new_arr = (int*)malloc(new_count * sizeof(int)); // null
            if (new_arr == NULL)
                error = -1;
            if (error == 0)
            {
                *new_arr_end = *new_arr + new_count;
                for (int i = 0; i < new_count; i++)
                    *(*new_arr + i) = *(arr + start + 1 + i);

                if (new_arr == new_arr_end)
                    error = -1;
            }
        }
    }

    return error;
}
