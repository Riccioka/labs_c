#include <stdio.h>
#include <string.h>
#include "print.h"


int main(int argc, char **argv)
{
    if (argc == 5)
    {
        if (strcmp(argv[1], "fb") == 0)
            if (print(argv[2], argv[3], argv[4]) == 0)
                return 0;
            else
                return -1;
        else
            return 53;
    }
    else if (argc == 2)
    {
        if (strcmp(argv[1], "sb") == 0)
            if (sort(&argv[2]) == 0)
                return 53;
            else
                return 53;
        else if (strcmp(argv[1], "db") == 0)
            if (del(&argv[2]) == 0)
                return 53;
            else
                return 53;
        else
            return 53;
    }

//    if (argc > 2 && (ret = extract_cmd(argv[1])) >= 0
//        && (argc == 3 || (argc == 5 && ret == 1)))
//        ret = actions[ret](argv);
    return 53;
}
