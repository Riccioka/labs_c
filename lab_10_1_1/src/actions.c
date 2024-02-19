#include "actions.h"
#include "memory_list.h"
#include "read_countries.h"
#include "print_countries.h"
#include "operations_with_element_list.h"
#include "operations_with_list.h"

void action_pf(node_t **head)
{
    country_t *pop = NULL;
    pop = pop_front(head);
    if (pop != NULL)
    {
        printf("Элемент удален с начала списка:\n");
        fprint_country(stdout, pop);
    }
}

void action_pb(node_t **head)
{
    country_t *pop = NULL;
    pop = pop_back(head);
    if (pop != NULL)
    {
        printf("Элемент удален с конца списка:\n");
        fprint_country(stdout, pop);
    }
}

int action_a(node_t **head, char *name_f_in, char *name_f_out)
{
    int rc = OK;
    FILE *f_in = NULL;
    f_in = fopen(name_f_in, "r");
    rc = check_file(f_in);
    if (!rc)
    {
        countries_t countries_2;
        default_array_country(&countries_2);
        rc = fread_countries(f_in, &countries_2.array, &countries_2.size);
        if (!rc)
        {
            node_t *head_b = NULL;
            for (int i = 0; i < countries_2.size && !rc; i++)
                rc = list_push(&head_b, countries_2.array + i);
            if (!rc)
            {
                append(head, &head_b);
                rc = fwrite_countries(name_f_out, *head);
            }
            free_list(&head_b);
        }
        free_struct_country(&countries_2.array, &countries_2.size);
        fclose(f_in);
    }

    return rc;
}

