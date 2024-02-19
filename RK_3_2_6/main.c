#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "funcs.h"


int main (int argc, char **argv)
{
    int rc = 0;
    if (argc !=2)
    {
        rc = -1;
        return rc;
    }

    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
        return -1;

    struct list_t list = {.head = NULL, .tail = NULL};
    list_from_file(f, &list);

    if (list.head == NULL)
    {
        printf("Empty list");
        return 0;
    }

    int imin = find_min(&list);

    printf("i_min = %d", imin);
    free_list(list.head);

    fclose(f);
    return rc;
}
