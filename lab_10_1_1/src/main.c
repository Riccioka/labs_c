#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs.h"

#include "memory_list.h"
#include "memory_countries.h"

#include "read_countries.h"
#include "checks.h"
#include "print_countries.h"
#include "errors.h"

#include "operations_with_element_list.h"
#include "operations_with_list.h"
#include "actions.h"

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);
    int rc = OK;

    char *action = argv[1];
    rc = check_argc(argc, action);
    if (rc != OK)
    {
        print_error(rc);
        return rc;
    }

    FILE *f = NULL;
    f = fopen(argv[2], "r");
    rc = check_file(f);
    if (rc != OK)
    {
        print_error(rc);
        fclose(f);
        return rc;
    }

    countries_t countries_1;
    default_array_country(&countries_1);
    rc = fread_countries(f, &countries_1.array, &countries_1.size);

    if (!rc)
    {
        node_t *head = NULL;

        for (int i = 0; i < countries_1.size && !rc; i++)
            rc = list_push(&head, countries_1.array + i);

        if (!rc)
        {
            if (argc == 4)
            {
                if (strcmp("pf", action) == 0)
                {
                    action_pf(&head);
                    rc = fwrite_countries(argv[3], head);
                }
                else if (strcmp("pb", action) == 0)
                {
                    action_pb(&head);
                    rc = fwrite_countries(argv[3], head);
                }
                else if (strcmp("s", action) == 0)
                {
                    head = sort(head, (int (*)(const void *, const void *)) comparator_name_country);
                    if (head != NULL)
                    {
                        printf("Список успешно отсортирован!\n");
                        rc = fwrite_countries(argv[3], head);
                    }
                }
            }
            else if (argc == 5 && (strcmp("a", action) == 0))
                rc = action_a(&head, argv[3], argv[4]);
        }
        free_list(&head);
    }
    free_struct_country(&countries_1.array, &countries_1.size);
    fclose(f);

    if (rc != OK)
        print_error(rc);

    return rc;
}