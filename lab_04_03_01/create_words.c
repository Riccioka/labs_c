#include <stdio.h>
#include <string.h>
#include "errors.h"

int create_words(char *str, char words[][17], char len_words[256])
{
    char *word = NULL;
    int len = 0, i = 0;

    word = strtok(str, ",;:-.!? ");
    if (strlen(word) > 16)
        return TOO_LONG_WORD;

    while (word != NULL)
    {
        while (word[i])
        {
            words[len][i] = word[i];
            i++;
        }
        words[len][i] = '\0';

        len_words[len] = strlen(word);
        len++;

        i = 0;
        word = strtok(NULL, ",;:-.!? ");
    }
    return len;
}
