#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "mysort.h"
#include <sys/time.h>
#include <inttypes.h>
#include <string.h>
#include "compare_sorts_time.h"

void fill_arr(int *arr, const size_t size)
{
    int elem; // случайное число

    for (size_t index = 0; index < size; index++)
    {
        elem = rand();
        arr[index] = elem;
    }
}

int *create_arr(const size_t size)
{
    int *temp_arr = malloc(size * sizeof(int));

    if (temp_arr)
    {
        fill_arr(temp_arr, size);
    }
    else
        temp_arr = NULL;

    return temp_arr;
}

int main()
{
    int *arr = NULL;
    clock_t start, end;
    double arr_time[10] = { 0 };

    size_t size = 100;

    arr = create_arr(size);

    if (arr)
    {
        start = clock();
        mysort(arr, size, sizeof(int), comparator);
        end = clock();
        arr_time[0] = (end - start) / (CLOCKS_PER_SEC * 1.0);

        free(arr);
    }
    arr = create_arr(size);
    if (arr)
    {
        start = clock();
        qsort(arr, size, sizeof(int), comparator);
        end = clock();
        arr_time[1] = (end - start) / (CLOCKS_PER_SEC * 1.0);

        free(arr);
    }

    size = 500;
    arr = create_arr(size);

    if (arr)
    {
        start = clock();
        mysort(arr, size, sizeof(int), comparator);
        end = clock();
        arr_time[2] = (end - start) / (CLOCKS_PER_SEC * 1.0);

        free(arr);
    }
    arr = create_arr(size);
    if (arr)
    {
        start = clock();
        qsort(arr, size, sizeof(int), comparator);
        end = clock();
        arr_time[3] = (end - start) / (CLOCKS_PER_SEC * 1.0);

        free(arr);
    }

    size = 1000;
    arr = create_arr(size);
    if (arr)
    {
        start = clock();
        mysort(arr, size, sizeof(int), comparator);
        end = clock();
        arr_time[4] = (end - start) / (CLOCKS_PER_SEC * 1.0);

        free(arr);
    }
    arr = create_arr(size);
    if (arr)
    {
        start = clock();
        qsort(arr, size, sizeof(int), comparator);
        end = clock();
        arr_time[5] = (end - start) / (CLOCKS_PER_SEC * 1.0);

        free(arr);
    }

    size = 5000;
    arr = create_arr(size);

    if (arr)
    {
        start = clock();
        mysort(arr, size, sizeof(int), comparator);
        end = clock();
        arr_time[6] = (end - start) / (CLOCKS_PER_SEC * 1.0);

        free(arr);
    }
    arr = create_arr(size);
    if (arr)
    {
        start = clock();
        qsort(arr, size, sizeof(int), comparator);
        end = clock();
        arr_time[7] = (end - start) / (CLOCKS_PER_SEC * 1.0);

        free(arr);
    }

    size = 8000;
    arr = create_arr(size);
    if (arr)
    {
        start = clock();
        mysort(arr, size, sizeof(int), comparator);
        end = clock();
        arr_time[8] = (end - start) / (CLOCKS_PER_SEC * 1.0);

        free(arr);
    }
    arr = create_arr(size);
    if (arr)
    {
        start = clock();
        qsort(arr, size, sizeof(int), comparator);
        end = clock();
        arr_time[9] = (end - start) / (CLOCKS_PER_SEC * 1.0);

        free(arr);
    }
    for (int i = 0; i < 10; i++)
        printf("%f\n", arr_time[i]);

    return 0;
}
