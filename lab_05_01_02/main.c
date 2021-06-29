#include <stdio.h>
#include "process.h"

int main(void)
{
    int res = 0;
    int ret = process(stdin, &res);

    if (ret == 0)
        printf("%d", res);

    return ret;
}
