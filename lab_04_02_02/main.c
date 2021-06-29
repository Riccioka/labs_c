#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my_strtok.h"
#include "strcmp_mod.h"
#include "remove_word_from_str.h"
#include "create_fst_str.h"


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
