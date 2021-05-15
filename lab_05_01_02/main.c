#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "process.h"

#define OK 0

int main(int argc, char **argv)
{
    if (argc != 2)
        return -1;
    FILE *f = fopen(argv[1], "r");
    int ret = 0;

    //printf("%p %d\n", f, process(f));
    ret = process(f);
    if (f)
        fclose(f);
    return ret;
}
