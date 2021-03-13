#include <stdio.h>

int fibb(int n)
{
    int pp = 0;
    int p = 1;
    int cur = 0;
    while (n-- > 0)
    {
        cur = pp + p;
        pp = p;
        p = cur;
    }
    return pp;
}

int main(void)
{
    int n = 0;
    scanf("%d", &n);
    printf("%d", fibb(n));
    return 0;
}
