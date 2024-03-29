#include "operations_with_element_list.h"

int comparator(const void *f_data, const void *s_data)
{
    int *a = (int *) f_data;
    int *b = (int *) s_data;

    return *a - *b;
}

int comparator_find_country(void *f_struct, void *s_struct)
{
    country_t *first = f_struct;
    country_t *second = s_struct;
    int res = 1;
    if (!strcmp(first->name_country, second->name_country) && !strcmp(first->name_capital, second->name_capital) && first->population == second->population)
        res = 0;

    return res;
}

void *pop_front(node_t **head)
{
    void *data = NULL;
    if (head != NULL && *head != NULL && (*head)->data != NULL)
    {
        data = (*head)->data;
        node_t *last_head = *head;
        *head = last_head->next;
        free(last_head);
    }

    return data;
}

void *pop_back(node_t **head)
{
    void *data = NULL;
    if (head != NULL && *head != NULL && (*head)->data != NULL)
    {
        node_t *prev = NULL;
        node_t *current = *head;

        for (; current->next; current = current->next)
            prev = current;

        if (prev)
            prev->next = NULL;
        else
            *head = NULL;

        data = current->data;
        free(current);
    }

    return data;
}