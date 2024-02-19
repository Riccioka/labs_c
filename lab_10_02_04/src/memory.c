#include "memory.h"
#include "errors.h"
#include "struct_list.h"

node_t *node_create(int data, int degree)
{
    node_t *node = NULL;
    node = (node_t *) malloc(sizeof(node_t));
    if (node != NULL)
    {
        node->data = data;
        node->degree = degree;
        node->next = NULL;
    }
    return node;
}

int list_push_front(node_t **head, int data, int degree)
{
    int rc = 0;
    if (head == NULL)
        rc = EMPTY_LIST;
    else
    {
        node_t *node = node_create(data, degree);
        if (node != NULL)
        {
            if (*head == NULL)
                *head = node;
            else
            {
                node->next = *head;
                *head = node;
            }
        }
        else
            rc = MEMORY_ERROR;
    }

    return rc;
}

int list_push_back(node_t **head, int last_num, int degree)
{
    int rc = 0;
    if (head == NULL)
        rc = EMPTY_LIST;
    else
    {
        node_t *node = node_create(last_num, degree);
        if (node != NULL)
        {
            if (*head == NULL)
                *head = node;
            else
            {
                node_t *tail = *head;
                for (;tail->next; tail = tail->next);
                tail->next = node;
            }
        }
        else
            rc = MEMORY_ERROR;
    }

    return rc;
}

void free_list(node_t **head)
{
    if (head != NULL && *head != NULL)
    {
        node_t *next_elem;

        for (;*head; *head = next_elem)
        {
            next_elem = (*head)->next;
            free(*head);
        }
        *head = NULL;
    }
}

char *allocate_malloc_string(int len)
{
    char *str = NULL;
    if (len > 0)
        str = malloc(len * sizeof(char));

    return str;
}

void free_malloc_string(char **str)
{
    if (str != NULL && *str != NULL)
    {
        free(*str);
        *str = NULL;
    }
}