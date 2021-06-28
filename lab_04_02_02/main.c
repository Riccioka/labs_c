#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_strtok.h"
#include "strcmp_mod.h"
#include "remove_word_from_str.h"

int main(void)
{
    char str[256], find[256];
    char fst_str[256][17], lens_str[256];
//    char words_arr[][17];
    char *res = (char*)str;
    char *words = NULL;
    int len = 0, len_fst = 0, i = 0;


    if (scanf("%256[^\n]%*c", str) != 1)
        return 1;
    if (scanf("%256[^\n]%*c", find) != 1)
        return 1;

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

//        printf("%s %s\n", word_copy, (strcmp_mod(find, word_copy, len) ? "yes" : "no"));
        remove_word_from_str(res, word, len);

    }

    printf("Result: ");

    for (i = 0; i < len_fst; i++)
    {
//        printf("fst: %s\n", fst_str[i]);
        printf("%s %s\n", fst_str[i], (strcmp_mod(find, fst_str[i], lens_str[i]) ? "yes" : "no"));
    }

    return 0;
}


//qwe  er    c  sf dsf      df g   aefegewr ddefrge df s   adf
