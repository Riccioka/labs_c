#include "checks.h"

int check_argc(int argc, char *action)
{
    int rc = EXIT_SUCCESS;
    if (argc <= 0)
        rc = PARAMS_ERROR;
    else
    {
        if (argc < 4 || argc > 5)
            rc = ARGC_ERROR;
        else if ((strcmp(action, "a") != 0 && strcmp(action, "m") != 0 && argc == 5) || (strcmp(action, "o") != 0 && argc == 4))
            rc = ACTION_ERROR;
    }

    return rc;
}

int check_file(FILE *f)
{
    int rc = EXIT_SUCCESS;
    if (f == NULL)
        rc = FILE_NOT_FOUND;
    else
    {
        fseek(f, 0, SEEK_END);
        long pos = ftell(f);
        if (pos <= 0)
        {
            rc = FILE_IS_EMPTY;
            fclose(f);
        }
        else
            fseek(f, 0, SEEK_SET);
    }

    return rc;
}

int check_matrix_params(const matrix_t *matrix)
{
    int rc = EXIT_SUCCESS;
    if (matrix->matrix != NULL || matrix->n > 0 || matrix->m > 0)
        rc = EXIT_FAILURE;

    return rc;
}