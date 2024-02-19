#include "mysort.h"

#include <string.h>
#include <stdio.h>

int comparator(const void *p1, const void *p2)
{
    int e1 = *((int *) p1);
    int e2 = *((int *) p2);

    return e1 - e2;
}

void swap(void *p1, void *p2, size_t size)
{
    char temp[size];

    memcpy(temp, p1, size);
    memcpy(p1, p2, size);
    memcpy(p2, temp, size);
}

void mysort(void *arr_b, size_t len, size_t size, int (*comparat)(const void *, const void *))
{
    char *arr = arr_b;
    if (!arr)
        return;

    int last_swap = len - 1;
    int prev_swap = last_swap;

    char *el_1, *el_2;

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < prev_swap; j++)
        {
            el_1 = arr + j * size;
            el_2 = arr + (j + 1) * size;

            if (comparat(el_1, el_2) > 0)
            {
                swap(el_1, el_2, size);
                last_swap = j;
            }
        }
        prev_swap = last_swap;
    }
}


