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
    ++cur;
    return str + cur - 1 - len_local;
}

int main(void)
{
    char str[256];
    char find[256];
    char word[16];
    if (scanf("%256[^\n]%*c", str) != 1)
        return 1;
    if (scanf("%256[^\n]%*c", find) != 1)
        return 1;

    char *res = NULL;
    int len = 0;

    while ((res = my_strtok(str, ",;:-.!? ", &len)))
    {
        char *word = strndup(res, len);
//        char *line = strstr(find, word);
        printf("%s %s\n", word, (strcmp(find, word) ? "no" : "yes"));
        free(word);
    }

    return 0;
}
