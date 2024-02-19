#include "use_funcs.h"
#include "find.h"
#include "product.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int check_if_str_is_num(char *str)
{
    int rc = OK;
    int len = strlen(str);

    for (int i = 0; i < len; i++)
        if (rc == 0)
            if (('0' <= str[i] && str[i] <= '9') == 0)
                rc = ERROR_NUM;

    return rc;
}

int read_structs(FILE *f, struct products *struct_arr, int count_structs)
{
    int rc = OK;

    int count = count_structs;

    if (rc == 0)
        for (int i = 0; i < count; i++)
            if (rc == 0)
                rc = read_product(f, struct_arr, i);

    return rc;
}

void free_all(struct products *struct_arr, struct products *new_arr, int structs_in_file)
{
    if (struct_arr != NULL)
    {
        for (int i = 0; i < structs_in_file; i++)
            if (struct_arr[i].name != NULL)
                free(struct_arr[i].name);

        free(struct_arr);
    }

    if (new_arr != NULL)
        free(new_arr);
}
