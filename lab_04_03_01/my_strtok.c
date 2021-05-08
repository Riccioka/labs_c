#include <string.h>

char *my_strtok(char **str, char *delim, int *len)
{
    int len_local = 0;
    char *ret = NULL;

    if (!str || !*str || !delim || **str == '\0')
        return NULL;
    while (**str)
    {
        if (strchr(delim, **str))
            break;
        len_local++;
        (*str)++;
    }
    *len = len_local;
    ret = *str - len_local;
    if (**str)
        (*str)++;
    return ret;
}
