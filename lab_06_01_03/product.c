#include "product.h"
#include "print_products.h"

void print_product(char *name, int price)
{
    printf("%s\n%d\n", name, price);
}

int read_product(FILE* filename, char *name, int *price)
{
    int er = OK;

    if (fgets(name, MAX_LEN + 1, filename) == NULL)
        er = INCORRECT_COUNT;
    else
    {
        if (name[strlen(name) - 1] == '\n')
            name[strlen(name) - 1] = '\0';
    }

    if (fscanf(filename, "%d\n", price) != 1 || *price < 0)
        er = INCORRECT_PRICE;

    return er;
}