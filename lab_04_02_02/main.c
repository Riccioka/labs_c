#include <stdio.h>
#include <string.h>
#include <assert.h>

char *my_strtok(const char *str, const char *sep)
{
//    char *str2_safe;

    while (*str)
    {
        if (*str == *sep)
            return (char*)str;
    }
    return (void*)0;
}

int main()
{
    char *my_strtok(const char *str, const char *sep);
    char str[256];
    char find[256];
    if (scanf("%s", str) != 1)
        return 1;
    if (scanf("%s", find) != 1)
        return 1;
    printf("tra ta ta: %p", my_strtok(str, " "));
    printf("the end");
    return 0;
}
