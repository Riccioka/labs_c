#include "product.h"
#include "arr_product.h"

void print_products(struct products *arr, int len)
{
    for (int i = 0; i < len; i++)
        print_product(&(arr[i]));
}