#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_strtok.h"
#include "strcmp_mod.h"
#include "remove_word_from_str.h"

int create_fst_str(char fst_str[][17], char *lens_str, char *res)
{
    char *words = NULL;
    int len = 0, i = 0, len_fst = 0;

    while ((words = my_strtok(&res, ",;:-.!? ", &len)))
    {
        if (!len)
            continue;

        char word[len + 1];

        for (i = 0; i != len; i++)
            word[i] = words[i];
        word[i] = '\0';

        for (i = 0; i != len + 1; i++)
            fst_str[len_fst][i] = word[i];

        lens_str[len_fst] = len;
        len_fst++;
        remove_word_from_str(res, word, len);
    }
    return len_fst;
}

int main(void)
{
    char str[256], find[256];
    char fst_str[256][17], lens_str[256];
    char *res = (char*)str;
    int i = 0;

    if (scanf("%256[^\n]%*c", str) != 1)
        return 1;
    if (scanf("%256[^\n]%*c", find) != 1)
        return 1;

    int len_fst = create_fst_str(fst_str, lens_str, res);

    printf("Result: ");

    for (i = 0; i < len_fst; i++)
        printf("%s %s\n", fst_str[i], (strcmp_mod(find, fst_str[i], lens_str[i]) ? "yes" : "no"));

    return 0;
}
