#include <stdio.h>
#include "struct.h"

int bad_size(FILE *fp)
{
    fseek(fp, 0, SEEK_END);
    size_t size_file = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    return (size_file % sizeof(t_student));
}
