#include "checks.h"

int check_file(FILE *f)
{
    int rc = OK;
    if (f == NULL)
        rc = FILE_NOT_FOUND;
    else
    {
        long size;
        fseek(f, 0, SEEK_END);
        size = ftell(f);
        if (size == 0)
        {
            rc = FILE_IS_EMPTY;
            fclose(f);
        }
        else
            fseek(f, 0, SEEK_SET);
    }

    return rc;
}

int check_argc(int argc, char *action)
{
    int rc = OK;

    if (argc < 4 || argc > 5 || action == NULL)
        rc = ARGC_ERROR;
    else
    {
        if (argc == 4 && strcmp("pf", action) != 0 && strcmp("pb", action) != 0 && strcmp("s", action) != 0)
            rc = ACTION_ERROR;
        else if (argc == 5 && strcmp("a", action) != 0)
            rc = ACTION_ERROR;
    }
    return rc;
}