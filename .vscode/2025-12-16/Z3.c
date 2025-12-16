#include <stdio.h>
#include <math.h>

int ProvjeriPravokutnik(int x1, int y1, int x2, int y2)
{
    if ((sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)) > 0) && (x2 != x1) && (y2 != y1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int IzracunajDuljinuStranice(int x1, int y1, int x2, int y2)
{
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

int IzracunajOpseg(int a, int b)
{
    return 2 * (a + b);
}
int IzracunajPovrsinu(int a, int b)
{
    return a * b;
}

void IzracunajOpsegPovrsinu(int *o, int *p)
{
    int x1, y1, x2, y2;
    printf("Unesite koordinate za tocku 1 > ");
    scanf("%d%d", &x1, &y1);
    printf("Unesite koordinate za tocku 2 > ");
    scanf("%d%d", &x2, &y2);
    if (!(ProvjeriPravokutnik(x1, y1, x2, y2)))
    {
        *o = -1;
        *p = -1;
        return;
    }
    int a;
    int b;
    a = IzracunajDuljinuStranice(x1, y1, x2, y1);
    b = IzracunajDuljinuStranice(x1, y1, x1, y2);
    *o = IzracunajOpseg(a, b);
    *p = IzracunajPovrsinu(a, b);
}