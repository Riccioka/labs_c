#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "my_strpbrk.h"

int main(void)
{
    char str[] = "example";
    return (strpbrk(str, "ex") != my_strpbrk(str, "ex"));
}
