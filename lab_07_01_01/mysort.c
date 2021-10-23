#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <unistd.h>

int comparator(const void *elem_1, const void *elem_2)
{
    const int *elem_1_to_char = elem_1;
    const int *elem_2_to_char = elem_2;
    if (*elem_1_to_char > *elem_2_to_char)
        return 1;
    else
        return -1;
}

void mysort(int new_count, int **new_arr, int (*comparator)(const void *, const void *))
{
    if (**new_arr > *(*new_arr + 1))
    {
        int time = **new_arr;
        **new_arr = *(*new_arr + 1);
        *(*new_arr + 1) = time;
    }

    int x = 0, left = 0, right = 0, mid = 0;

    for (int i = 2; i < new_count; i++)
        if (*(*new_arr + i - 1) > *(*new_arr + i))
//        if ((comparator((*new_arr + i - 1), (*new_arr + i)) > 0) == 1) //
        {
            x = *(*new_arr + i); //arr+1
            left = 0; //1
            right = i - 1;

            while (left <= right)
            {
                mid = (left + right) / 2;
                if (*(*new_arr + mid) < x)
                    left = mid + 1;
                else
                    right = mid - 1;
            }

            for (int j = i-1; j >= left; j--) // >
                *(*new_arr + j + 1) = *(*new_arr + j);
            *(*new_arr + left) = x;
        }

//    for (int i = 0; i < new_count; i++)
//        printf("%d ", *(*new_arr + i));
//    printf("\n");
}
