#include <stdio.h>
#include "print.h"


int main(int argc, char **argv)
{
    int ret = 53;
    int (*actions[])(char **) = { sort, print, del };

    if (argc > 2 && (ret = extract_cmd(argv[1])) >= 0
        && (argc == 3 || (argc == 5 && ret == 1)))
        ret = actions[ret](argv);
    return ret;
}
