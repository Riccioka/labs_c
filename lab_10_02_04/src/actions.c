#include <stdio.h>
#include <stdlib.h>

#include "struct_list.h"
#include "errors.h"
#include "memory.h"
#include "read_action_and_num.h"
#include "math_operation_list.h"
#include "print_list.h"
#include "actions.h"

int action_out(void)
{
    int rc = 0;

    int num = 0;
    rc = read_num(&num);
    if (rc == 0)
    {
        node_t *list = NULL;
        rc = translate_num_in_list(&list, num);
        if (rc == 0)
            rc = print_list(list);
        free_list(&list);
    }

    return rc;
}

int action_mul(void)
{
    int rc = 0;

    int num_1 = 0, num_2 = 0;
    rc = read_num(&num_1);
    if (rc)
        return rc;

    rc = read_num(&num_2);
    if (rc)
        return rc;

    node_t *list_1 = NULL, *list_2 = NULL, *result = NULL;
    rc = translate_num_in_list(&list_1, num_1);
    if (!rc)
    {
        rc = translate_num_in_list(&list_2, num_2);
        if (!rc)
        {
            rc = multiply_lists(&result, list_1, list_2);
            if (!rc)
                rc = print_list(result);
        }
    }
    free_list(&list_1);
    free_list(&list_2);
    free_list(&result);

    return rc;
}

int action_div(void)
{
    int rc = 0;

    int num_1 = 0, num_2 = 0;
    rc = read_num(&num_1);
    if (!rc)
    {
        rc = read_num(&num_2);
        if (!rc)
        {
            node_t *list_1 = NULL, *list_2 = NULL, *result = NULL;
            rc = translate_num_in_list(&list_1, num_1);
            if (!rc)
            {
                rc = translate_num_in_list(&list_2, num_2);
                if (!rc)
                {
                    rc = divide_lists(&result, list_1, list_2);
                    if (!rc)
                        rc = print_list(result);
                }
            }
            free_list(&list_1);
            free_list(&list_2);
            free_list(&result);
        }
    }

    return rc;
}

int action_sqr(void)
{
    int rc = 0;

    int num = 0;
    rc = read_num(&num);
    if (!rc)
    {
        node_t *result = NULL, *list = NULL;
        rc = translate_num_in_list(&list, num);
        if (!rc)
        {
            rc = sqr_list(&result, list);
            if (!rc)
                rc = print_list(result);
        }
        free_list(&list);
        free_list(&result);
    }

    return rc;
}