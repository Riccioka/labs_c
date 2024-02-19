#include "product.h"
#include "print_products.h"
#include "read_file.h"
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char **argv)
{
    int er = OK;
    product products[MAX_COUNT];

    if (argc != 3)
    {
        er = INCORRECT_INPUT;
        return er;
    }

    const char *filename = argv[1];
    int count = 0;

    er = read_file(filename, products, &count);

    if (er)
        return er;

    char *str = argv[2];
    char *str_er;

    int price = strtol(str, &str_er, 10);
    if (price != '\0' && *str_er == '\0')
        print_products(products, count, price);
    else
    {
        er = INCORRECT_PRICE;
        return er;
    }

    return OK;
}