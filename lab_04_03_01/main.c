#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "my_strtok.h"
#include "my_strlen.h"

int main(void)
{
    char str[1000] = { 0 }, words[256][17], len_words[256];
    char new_str[256] = { 0 };
//    char *res = (char*)str;
    int symbol[17];
    char *word = NULL;
    int len = 0, i = 0, len_new = 0, flag = 1;

    scanf("%1000[^\n]%*c", str);
    if (strlen(str) > 256)
        return 1;

    int f = 0;
    for (int i = 0; i < my_strlen(str); i++)
        if (!isspace(str[i]))
            f = 1;
    if (f == 0)
        return -1;

    word = strtok(str, ",;:-.!? ");
    if (strlen(word) > 16)
        return 3;

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

    for (i = len - 2; i != -1; i--)
    {
        if (strcmp(words[i], words[len-1]))
        {
            for (int j = 0; j != len_words[i]; j++)
            {
                char *index = strchr(words[i], words[i][j]);
                symbol[j] = *index;
                for (int k = 0; k != j; k++)
                    if (symbol[k] == symbol[j])
                        flag = 0;
                if (flag)
                {
                    new_str[len_new] = words[i][j];
                    len_new++;
                }
                flag = 1;
            }
            new_str[len_new] = ' ';
            len_new++;
        }

    }
    if (len_new == 0)
        return -1;
    printf("Result: %s\n", new_str);

    return 0;
}


