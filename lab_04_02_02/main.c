#include <stdio.h>
#include <string.h>
#include <assert.h>

char* my_strtok(const char *str, const char *sep)
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
    printf("tra ta ta: %p", my_strtok("qw er ty", " "));
    return 0;
}
