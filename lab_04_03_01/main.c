#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "my_strtok.h"
#include "my_strlen.h"

typedef struct s_word
{
    char *word;
    size_t len;
} t_word;

typedef struct s_sentence
{
    t_word *words;
    size_t wc;
} t_sentence;

int main(void)
{
    char str[1000] = { 0 };
    t_sentence s = { .words = NULL, .wc = 0 };
    char *res = (char*)str;
    char *word = NULL;
    int len = 0;

    scanf("%1000[^\n]%*c", str);
    if (my_strlen(str) > 256)
        return 1;
    int f = 0;
    for (int i = 0; i < my_strlen(str); i++)
        if (!isspace(str[i]))
            f = 1;
    if (f == 0)
        return -1;
    while ((word = my_strtok(&res, ",;:-.!? ", &len)))
    {
        if (!len)
            continue;
        s.wc++;
        s.words = realloc(s.words, s.wc * sizeof(t_word));
        s.words[s.wc - 1].word = calloc(sizeof(char), len + 1);
        s.words[s.wc - 1].len = len;
        strncpy(s.words[s.wc - 1].word, word, len);
    }

    len = 1;
    f = 0;
    for (int i = s.wc - 2; i >= 0; --i)
    {
        if (strcmp(s.words[i].word, s.words[s.wc - 1].word))
        {
            if (len)
            {
                --len;
                printf("Result: ");
                f = 1;
            }
            if (f == 1)
            {
                for (size_t j = 0; j < s.words[i].len; ++j)
                    if (strchr(s.words[i].word, s.words[i].word[j]) == s.words[i].word + j)
                        printf("%c", s.words[i].word[j]);

                if (i)
                    printf(" ");
            }
        }
    }
    for (size_t i = 0; i < s.wc; ++i)
        free(s.words[i].word);
    free(s.words);
    if (f == 0)
        return 1;
    if (!len)
        printf("\n");
    return 0;
}

