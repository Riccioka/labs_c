#include <ctype.h>

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
