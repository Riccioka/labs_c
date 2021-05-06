#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ",;:-.!? "

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

int main(void)
{
    char str[256];
    char find[256];
    char *res = (char*)str;
    char *word = NULL;
    int len = 0;


    if (scanf("%256[^\n]%*c", str) != 1)
        return 1;
    if (scanf("%256[^\n]%*c", find) != 1)
        return 1;

    while ((word = my_strtok(&res, ",;:-.!? ", &len)))
    {
        if (!len)
            continue;
        char *word_copy = calloc(sizeof(char), len + 1);
        strncpy(word_copy, word, len);
        printf("%s %s\n", word_copy, (strcmp_mod(find, word_copy, len) ? "yes" : "no"));
        remove_word_from_str(res, word, len);
        free(word_copy);
    }

    return 0;
}
