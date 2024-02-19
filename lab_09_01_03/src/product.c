#include "find.h"
#include "product.h"
#include <string.h>
#include <stdlib.h>

void print_product(struct products *product)
{
    printf("%s\n%d\n", product->name, product->price);
}

int read_product(FILE *f, struct products *struct_arr, int i)
{
    int rc = OK;
    int price;
    int len = find_name_len(f);

    char *name = malloc(len + 1);
    if (name == NULL)
        return MEMORY_ERROR;

    if (name == NULL)
        rc = TOO_LONG;

    if (fgets(name, len + 1, f) == NULL)
        rc = ERROR_FILE;

    if (rc == 0 && len == 0)
        rc = INCORRECT_NAME;
    else if (fscanf(f, "%d\n", &price) != 1)
        rc = ERROR_READ;
    else if (price <= 0)
        rc = ERROR_PRICE;

    if (rc != 0)
        free(name);
    else
    {
        struct_arr[i].name = name;
        struct_arr[i].price = price;
    }
    return rc;
}


