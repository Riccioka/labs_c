#include "find.h"
#include "arr_product.h"
#include "use_funcs.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int rc = OK;

    if (argc != 3)
        rc = INCORRECT_ARG;

    FILE *f = NULL;

    if (rc == 0)
    {
        f = fopen(argv[1], "r");
        if (f == NULL)
            rc = ERROR_FILE;
    }

    struct products *arr = NULL;
    int count_structs, new_len = 0;

    if (rc == 0)
    {
        rc = find_num_of_structs(f, &count_structs);

        if (rc == 0)
        {
            arr = malloc(count_structs * sizeof(struct products));
            if (arr != NULL)
            {
                for (int i = 0; i < count_structs; i++)
                    arr[i].name = NULL;

                rc = read_structs(f, arr, count_structs);

                if (rc == 0 && check_if_str_is_num(argv[2]) == ERROR_NUM)
                    rc = ERROR_NUM;
            }
            else
                rc = MEMORY_ERROR;
        }
    }

    struct products *new_arr = NULL;
    if (rc == 0)
    {
        float max_price = strtof(argv[2], NULL);
        new_len = find_new_len(arr, count_structs, max_price);

        if (new_len > 0)
        {
            new_arr = malloc(new_len * sizeof(struct products));
            if (arr != NULL)
            {
                find_cheapest(arr, count_structs, new_arr, max_price);

                print_products(new_arr, new_len);
            }
            else
                rc = MEMORY_ERROR;
        }
    }

    if (f != NULL)
        fclose(f);

    free_all(arr, new_arr, count_structs);

    return rc;
}
