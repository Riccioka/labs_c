#include "find.h"
#include "use_funcs.h"
#include "product.h"

int find_name_len(FILE *f)
{
    int len = 0;
    char ch = 0;
    int place = ftell(f);

    while (fscanf(f, "%c", &ch) == 1 && ch != '\n')
        len++;

    fseek(f, place, 0);

    return len;
}

int find_new_len(struct products *struct_arr, int count, int max_price)
{
    int new_len = 0;

    for (int i = 0; i < count; i++)
        if (struct_arr[i].price < max_price)
            new_len++;

    return new_len;
}

int find_num_of_structs(FILE *f, int *structs_in_file)
{
    int rc = 0;

    if (fscanf(f, "%d\n", structs_in_file) != 1)
        rc = EMPTY_FILE;
    else if (*structs_in_file <= 0)
        rc = INCORRECT_COUNT_OF_STRUCTS;

    return rc;
}

void find_cheapest(struct products *struct_arr, int count, struct products *new_arr, float top_price)
{
    int new_len = 0;

    for (int i = 0; i < count; i++)
        if (struct_arr[i].price < top_price)
        {
            new_arr[new_len].name = struct_arr[i].name;
            new_arr[new_len].price = struct_arr[i].price;
            new_len++;
        }
}
