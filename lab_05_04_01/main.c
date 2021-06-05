#include <stdio.h>
#include <string.h>
#include "print.h"


int main(int argc, char **argv)
{
    int ret = 53;
    if (argc == 5 && !strcmp(argv[1], "fb"))
        ret = print(argv[2], argv[3], argv[4]);
    else if (argc == 3 && !strcmp(argv[1], "sb"))
        ret = sort(argv[2]);
    else if (argc == 3 && !strcmp(argv[1], "db"))
        ret = del(argv[2]);

    return ret;
}
