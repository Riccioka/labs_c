#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// ",;:-.!? "

char *my_strtok(char *str, char *delim, int *len)
{
    static int cur = 0;
    int len_local = 0;

    if (!str || !delim || str[cur] == '\0')
        return NULL;
    while (str[cur])
    {
        if (strchr(delim, str[cur]))
            break;
        len_local++;
        cur++;
    }
    *len = len_local;
    cur++;
    printf("%p", str + cur - 1 - len_local);
    return str + cur - 1 - len_local;
}

int strcmp_mod(char *str, char *word, int len)
{
    char *res = NULL;
    int len2 = 0;

    while ((res = my_strtok(str, ",;:-.!? ", &len2)))
    {
        if (len == len2 && !strncmp(res, word, len))
            return 1;
    }
    return 0;
}

int main(void)
{
    char str[256];
    char find[256];
    if (scanf("%256[^\n]%*c", str) != 1)
        return 1;
    if (scanf("%256[^\n]%*c", find) != 1)
        return 1;
    printf("im here");
    char *res = NULL;
    int len = 0;

    while ((res = my_strtok(str, ",;:-.!? ", &len)))
    {
        char *word = calloc(sizeof(char), len + 1);
        strncpy(word, res, len);
        printf("%s %s\n", word, (strcmp_mod(find, word, len) ? "no" : "yes"));
        free(word);
    }

    return 0;
}
