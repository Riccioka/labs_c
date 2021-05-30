#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define OK 0
#define ERROR_OPEN -2
#define ERROR_FILE -3

int process(FILE *f, int *m)
{
    int count = 0;
    int num = 0;
    int res = 0;
    int max = INT_MIN;
    int max_ind = -1;

    if (f == NULL || feof(f) || !m)
        return ERROR_OPEN;
    while ((res = fscanf(f, "%d", &num)) == 1)
    {
        count++;
        if (num > max)
        {
            max = num;
            max_ind = count;
            *m = max_ind;
        }
    }
    if (res == EOF)
        return OK;
    return ERROR_FILE;
}

int main(void)
{
    int res = 0;
    int ret = process(stdin, &res);

    if (ret == OK)
        printf("%d", res);

    return ret;
}
