#include "math_operation_list.h"
#include "read_action_and_num.h"
#include "simple_num.h"
#include "memory.h"
#include <math.h>

int translate_list_in_num(node_t *list, int *num)
{
    int rc = 0;
    if (list == NULL)
        rc = PARAMS_ERROR;
    else
    {
        *num = 1;

        while (list != NULL)
        {
            *num *= (int)pow(list->data, list->degree);

            list = list->next;
        }
    }

    return rc;
}

int translate_num_in_list(node_t **list, int num)
{
    int rc = 0;
    if (list == NULL || *list != NULL)
        rc = PARAMS_ERROR;
    else
    {
        if (num < LIMIT_TRANSLATE)
            rc = TASK_ERROR;
        else
        {
            int last_num = 1;
            int degree = 0;

            while (num != 1 && !rc)
            {
                last_num = get_simple_num(last_num);
                if (last_num == INT_MAX)
                    rc = TASK_ERROR;
                else
                {
                    while (num % last_num == 0)
                    {
                        num /= last_num;
                        degree++;
                    }
//                    printf("degree = %d\n", degree);
                    if (degree)
                    {
                        rc = list_push_front(list, last_num, degree);
                        degree = 0;
                    }
                }
            }
        }
    }

    return rc;
}

int multiply_lists(node_t **result, node_t *list_1, node_t *list_2)
{
    int rc = 0;

    if (result == NULL || *result != NULL || list_1 == NULL || list_2 == NULL)
        rc = PARAMS_ERROR;
    else
    {
        int div_1, div_2;
        translate_list_in_num(list_1, &div_1);
        translate_list_in_num(list_2, &div_2);

        int res_num = div_1 * div_2;

        rc = translate_num_in_list(result, res_num);
    }

    return rc;
}

int divide_lists(node_t **result, node_t *list_1, node_t *list_2)
{
    int rc = 0;

    if (result == NULL || *result != NULL || list_1 == NULL || list_2 == NULL)
        rc = PARAMS_ERROR;
    else
    {
        int div_1, div_2;
        translate_list_in_num(list_1, &div_1);
        translate_list_in_num(list_2, &div_2);
        if (div_2 == 0)
            rc = DIVIDE_ERROR;
        else
        {
            int res_num = 0;
            if (div_1 != 0)
                res_num = div_1 / div_2;
            rc = translate_num_in_list(result, res_num);
        }
    }

    return rc;
}

int sqr_list(node_t **result, node_t *list)
{
    int rc = 0;
    if (result == NULL || *result != NULL || list == NULL)
        rc = PARAMS_ERROR;
    else
        rc = multiply_lists(result, list, list);

    return rc;
}