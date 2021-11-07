#include <stdio.h>
#include "../inc/key.h"

int key_check()
{
    int test_arr[5];
    test_arr[0] = 5;
    test_arr[1] = 10;
    test_arr[2] = -10;
    test_arr[3] = 5;
    test_arr[4] = 15;
    int *b;
    int *e;
    key(test_arr, test_arr + 5, &b, &e);
    int *temp = b;
    while (temp != e)
    {
        printf("%d", *b);
        temp++;
    }

    return 0;
}

