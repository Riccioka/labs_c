#include <stdio.h>
#include "my_strlen.h"
#include "validation_check.h"

int main(void)
{
    char str[256] = { 0 };
    int c = 0;

    scanf("%[^\n]%*c", str);
    if (my_strlen(str) > 256)
        return 1;

    if ((c = is_valid_ip(str)))
        printf("YES");
    else
        printf("NO");

    return 0;
}
