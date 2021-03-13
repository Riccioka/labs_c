#include <stdio.h>
#include <locale.h>
int f(f0, f1)
{
    return  f0 + f1;
}

int main()
{
    int n, f0, f1, el;
    f0 = el = 0;
    f1 = 1;
    scanf("%d", &n);
    if (n < 0)
        return 1;
    int tmp;
    if (n == 0)
        printf("Number = %s", "0");
    else
    {
        while (n - 1 > 0)
        {
            tmp = f1;
            f1 = f(f0, f1);
            f0 = tmp;
            n -= 1;
        }
        printf("Number = %d", f1);
    }
    return 0;
}
