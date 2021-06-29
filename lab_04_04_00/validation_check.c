#include <ctype.h>

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
    int count_null = 0;
    while (isdigit(**str))
    {
        if (**str == '0')
            count_null++;
        c = c * 10 + (**str - '0');
        if (c > 255)
            return -1;
        (*str)++;
        count++;
    }
    if (count_null > 3)
        return -1;
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
