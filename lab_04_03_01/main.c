#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "transformation.h"
#include "create_words.h"
#include "errors.h"

int main(void)
{
    char str[1000] = { 0 }, words[256][17], len_words[256];
    char new_str[256] = { 0 };
    int len = 0, len_new = 0;

    scanf("%1000[^\n]%*c", str);
    if (strlen(str) > 256)
        return TOO_LONG_STRING;

    int f = 0;
    for (unsigned long long i = 0; i < strlen(str); i++)
        if (!isspace(str[i]))
            f = 1;
    if (f == 0)
        return NOT_ENOUGH_WORDS;

    len = create_words(str, words, len_words);

    len_new = transformation(len, words, len_words, new_str);

    if (len_new == 0)
        return EMPTY_STRING;

    printf("Result: %s\n", new_str);

    return 0;
}


