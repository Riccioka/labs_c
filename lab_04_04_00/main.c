#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int my_strlen(const char *str)
{
    int count = 0;
    while (*str++)
        ++count;
    return count;
}

char *skip_spaces(char *str)
{
    while (*str == ' ' || *str == '\t')
        ++str;
    return str;
}

int my_atoi_mod(char **str)
{
    int c = 0;
    int count = 0;

    while (isdigit(**str))
    {
        c = c * 10 + (**str - '0');
        if (c > 255)
            return -1;
        (*str)++;
        count++;
    }
    return (count) ? c : -1;
}

int is_valid_ip(char *str)
{
    char *walker = str;
    int c = 0;

    walker = skip_spaces(walker);

    c = my_atoi_mod(&walker);
    if (c < 0 || *walker != '.')
        return 0;

    walker++;
    c = my_atoi_mod(&walker);
    if (c < 0 || *walker != '.')
        return 0;

    walker++;
    c = my_atoi_mod(&walker);
    if (c < 0 || *walker != '.')
        return 0;

    walker++;
    c = my_atoi_mod(&walker);
    return (c >= 0 && *skip_spaces(walker) == 0);
}

int main(void)
{
    char str[256] = { 0 };
    int c = 0;

//    scanf("%256[^\n]%*c", str);
    scanf("%c", str);
    if (!fgets(str, 256, stdin))
        return 1;

    if ((c = is_valid_ip(str)))
        printf("YES");
    else
        printf("NO");

    return 0;
}
