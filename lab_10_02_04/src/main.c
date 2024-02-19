#include <stdio.h>
#include <stdlib.h>

#include "read_action_and_num.h"
#include "actions.h"

int main(void)
{
    int rc = 0, action = 0;
    rc = read_action(&action);
    if (!rc)
    {
        if (action == OUT)
            rc = action_out();
        else if (action == MUL)
            rc = action_mul();
        else if (action == SQR)
            rc = action_sqr();
        else if (action == DIV)
            rc = action_div();
    }

    return rc;
}