#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "put_number_by_pos.h"
#include "c.h"
#include "p.h"
#include "s.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool failflag = false;

int get_number_by_pos(FILE *fp, int pos)
{
    int n = 0;
    fseek(fp, pos * sizeof(n), SEEK_SET);
    if (!feof(fp)) failflag = (fread(&n, sizeof(n), 1, fp) == 0); else failflag = true;
    return n;
}
