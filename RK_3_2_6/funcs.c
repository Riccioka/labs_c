#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "funcs.h"

struct node_t *create_node(int num)
{
    struct node_t *node = malloc(sizeof (struct node_t));
    node->num = num;
    node->next = NULL;

    return node;
}

void list_add_tail(struct list_t *list, struct node_t *node)
{
    if(list->head ==NULL && list->tail == NULL)
    {
        list->head = node;
        list->tail =node;

    }
    else
    {
        list->tail->next = node;
        list->tail = node;
    }
}

void list_from_file(FILE *f, struct list_t *list)
{
    int num = 0;
    while ((fscanf(f, "%d\n", &num)) == 1)
    {
        struct node_t *node = create_node(num);
        if (node)
            list_add_tail(list, node);
    }
}

void free_node(struct node_t *node)
{
    free(node);
}

void free_list(struct node_t *head)
{
    struct node_t *next = head;
    while (next)
    {
        next = head->next;
        free(head);
        head = next;
    }
}

int find_min(struct list_t *list)
{
    struct node_t *node = list->head;
    int min = node->num;
    int count = 1, i = 0;
    while (node)
    {
        if (node->num <= min)
        {
            min = node->num;
            i = count;
        }
        count++;

        node = node->next;
    }

    return i;
}

