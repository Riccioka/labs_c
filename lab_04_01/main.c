#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "my_strpbrk.h"

int main(void)
{
    char str[256];
    char find[256];
    if (scanf("%256s", str) != 1)
        return 1;
    if (scanf("%256s", find) != 1)
        return 1;
    return(strpbrk(str, find) != my_strpbrk(str, find));
}
