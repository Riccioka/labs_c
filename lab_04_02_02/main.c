#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my_strtok.h"
#include "working_with_words.h"
#include "create_fst_str.h"

#define INVALID_STRING -1
#define OK 0

int main(void)
{
    char str[256], find[256];
    char fst_str[256][17], lens_str[256];
    char *res = (char*)str;
    int i = 0;

    if (scanf("%256[^\n]%*c", str) != 1)
        return INVALID_STRING;
    if (scanf("%256[^\n]%*c", find) != 1)
        return INVALID_STRING;

    int len_fst = create_fst_str(fst_str, lens_str, res);

    printf("Result: ");

    for (i = 0; i < len_fst; i++)
        printf("%s %s\n", fst_str[i], (strcmp_mod(find, fst_str[i], lens_str[i]) ? "yes" : "no"));

    return OK;
}
