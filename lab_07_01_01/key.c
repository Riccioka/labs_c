#include <stdio.h>
#include <string.h>
#include <malloc.h>


int key(int *arr, int *arr_end, int **new_arr, int **new_arr_end)
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
    int new_count = end - start - 1;
//
    *new_arr = (int*)malloc(new_count * sizeof(int));
    *new_arr_end = *new_arr + new_count;
    for (int i = 0; i < new_count; i++)
        *(*new_arr + i) = *(arr + start + 1 + i);

//    for (int i = 0; i < new_count; i++)
//        printf("arr: %d  ", *(*new_arr + i));
//    printf("\n");
    return new_count;
}
