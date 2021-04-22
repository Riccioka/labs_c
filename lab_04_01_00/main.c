#include <stdio.h>
#include <string.h>
#include <assert.h>

char* my_strpbrk(const char *str1, const char *str2)
{
    char *str2_safe;

    while (*str1)
    {
        str2_safe = (char*)str2;
        while (*str2_safe)
        {
            if (*str1 == *str2_safe)
                return (char*)str1;
            str2_safe++;
        }
        str1++;
    }
//    return 0;
    return (void*)0;
}

int main(void)
{
    char* my_strpbrk(const char *str1, const char *str2);
    char str[100];
    char find[100];
    if (scanf("%s", str) != 1)
        return 1;
    if (scanf("%s", find) != 1)
        return 1;

    assert(strpbrk(str, find) == my_strpbrk(str, find));

//    if (res)
    printf("%s", my_strpbrk(str, find));
    return 0;
}
