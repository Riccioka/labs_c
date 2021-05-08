#include <string.h>
#include "my_strtok.h"

int strcmp_mod(char *str, char *word, int len)
{
    char *res = NULL;
    int len2 = 0;

    while ((res = my_strtok(&str, ",;:-.!? ", &len2)))
    {
        if (len == len2 && !strncmp(res, word, len))
            return 1;
    }
    return 0;
}
