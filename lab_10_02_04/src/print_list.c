#include "print_list.h"

int print_list(node_t *head)
{
    int rc = 0;
    if (head == NULL)
        rc = EMPTY_LIST;
    else
    {
        node_t *current = head;

        while (current != NULL)
        {
            printf("%d ", current->data);
            printf("%d ", current->degree);
            current = current->next;
        }

        printf("%d", 1);
    }

    return rc;
}
