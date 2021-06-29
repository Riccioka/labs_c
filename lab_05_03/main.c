#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "get_number_by_pos.h"
#include "put_number_by_pos.h"
#include "c.h"
#include "p.h"
#include "s.h"


int main(int argc, char **argv)
{
    srand(time(NULL));

    if (argc > 4 || argc < 3 || strlen(argv[1]) != 1)
        return -1;
    if (argc == 4 && argv[1][0] == 'c')
        return c(argv[argc - 1], atoi(argv[2]));
    else if (argc == 3 && argv[1][0] == 'p')
        return p(argv[argc - 1]);
    else if (argc == 3 && argv[1][0] == 's')
        return s(argv[argc - 1]);
    return -1;
}
