#include "product.h"
#include "read_file.h"

int read_file(const char *filename, product *products, int *count)
{
    FILE *f;
    f = fopen(filename, "r");
    int er = OK;

    if (f == NULL)
        return NON_EXISTENT_FILE;

    int i = 0, len;

    if (fscanf(f, "%d\n", &len) != 1)
        er = INCORRECT_COUNT;

    if (!er)
    {
        while (!feof(f) && !er)
        {
            er = read_product(f, products[i].name, &products[i].price);
            i++;

            if (i > MAX_COUNT)
                er = INCORRECT_COUNT;
        }
        *count = i;
        fclose(f);
    }
    return er;
}