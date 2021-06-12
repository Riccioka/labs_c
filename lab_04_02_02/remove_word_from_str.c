#include <string.h>
#include "my_strtok.h"

void remove_word_from_str(char *str, char *word, int len)
{
    char *res = NULL;
    int len2 = 0;

    while ((res = my_strtok(&str, ",;:-.!? ", &len2)))
    {
        if (len == len2 && !strncmp(res, word, len))
            for (int i = 0; i < len; ++i)
                res[i] = ' ';
    }
}
