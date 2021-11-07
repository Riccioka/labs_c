#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int comparator(const void *elem_1, const void *elem_2)
{
    const int *elem_1_to_char = elem_1;
    const int *elem_2_to_char = elem_2;
    if (*elem_1_to_char < *elem_2_to_char)
        return -1;
    else if (*elem_1_to_char > *elem_2_to_char)
        return 1;
    else
        return 0;
}

void mysort(void *const arr, size_t count, size_t size, int (*comparator)(const void *, const void *))
{
    qsort(arr, count, size, comparator);

//    int *pb = arr;

//    int x = 0, left = 0, right = 0, mid = 0;

//    int i = 1;
//    while (i < (int)count)
//    {
//        if (comparator(pb + i - 1, pb + i - 1 + size / 4) > 0)
//        {
//            x = *(pb + i);
//            left = 0;
//            right = i - 1;

//            while (left <= right)
//            {
//                mid = (left + right) / 2;
//                if (*(pb + mid) < x)
//                    left = mid + 1;
//                else
//                    right = mid - 1;
//            }
//            for (int j = i - 1; j >= left; j--)
//                *(pb + j + 1) = *(pb + j);
//            *(pb + left) = x;
//        }
//        i++;
//    }
//    for (int i = 0; i < (int)count; i++)
//        printf("%d ", *(pb + i));
//    printf("\n");
}
