#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_strtok.h"
#include "strcmp_mod.h"
#include "remove_word_from_str.h"

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
    printf("Result: ");
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
