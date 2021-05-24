#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define OK 0
#define ERROR_OPEN -2
#define ERROR_FILE -3

int process(FILE *f)
{
    int count = 0;
    int num = 0;
    int res = 0;
    int max = INT_MIN;
    int max_ind = -1;

    if (f == NULL || feof(f))
        return ERROR_OPEN;
    while ((res = fscanf(f, "%d", &num)) == 1)
    {
        count++;
        if (num > max)
        {
            max = num;
            max_ind = count;
        }
    }
    if (res == EOF)
        return 0;
    return ERROR_FILE;
}
