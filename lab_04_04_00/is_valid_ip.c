#include "skip_spaces.h"
#include "my_atoi_mod.h"

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
