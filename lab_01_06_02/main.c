#include <stdio.h>

int func(float xp, float yp, float xa, float ya, float xb, float yb)
{
    return  (xa - xp) * (yb-ya) - (xb - xa) * (ya - yp);

}


int main()
{
    float xp, yp, xa, ya, xb, yb, xc, yc;
    printf("Введите абсциссу P: ");
    scanf("%f", &xp);
    printf("Введите ординату P: ");
    scanf("%f", &yp);
    printf("Введите абсциссу А: ");
    scanf("%f", &xa);
    printf("Введите ординату А: ");
    scanf("%f", &ya);
    printf("Введите абсциссу B: ");
    scanf("%f", &xb);
    printf("Введите ординату B: ");
    scanf("%f", &yb);
    printf("Введите абсциссу C: ");
    scanf("%f", &xc);
    printf("Введите ординату C: ");
    scanf("%f", &yc);

    if ((func(xp, yp,xa, ya, xb, yb) > 0) &&
        (func(xp, yp,xb, yb, xc, yc) > 0) && (func(xp, yp,xc, yc, xa, ya) > 0))
    {
        printf("0");
    }

    else if ((func(xp, yp,xa, ya, xb, yb) < 0) &&
    (func(xp, yp,xb, yb, xc, yc) < 0) && (func(xp, yp,xc, yc, xa, ya) < 0))
    {
        printf("0");
    }

    else if ((func(xp, yp,xa, ya, xb, yb)) *
             (func(xp, yp,xb, yb, xc, yc)) * (func(xp, yp,xc, yc, xa, ya)) == 0)
    {
        printf("1");
    }

    else
    {
        printf("2");
    }
    return 0;
}
