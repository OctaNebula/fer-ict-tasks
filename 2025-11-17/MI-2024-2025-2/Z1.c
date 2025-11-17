#include <stdio.h>

int main()
{
    int n = -1;
    printf("Unesite duljinu polja > \n");
    while (!(n > 0 && n < 100))
    {
        scanf("%d", &n);
    }
    int samenumber = 0;
    int count = 1;
    int n2;
    int maxcount = -1;
    int currindex = 0;
    int maxindex = 0;
    int rebound = 0;

    printf("Unesite clanove polja > \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &n2);
        if (samenumber == n2)
        {
            count += 1;
            if (rebound == 0)
            {
                currindex = i - 1;
                rebound = 1;
            }
        }
        else // if it detects a change
        {
            if (count > maxcount)
            {
                maxcount = count;
                maxindex = currindex;
            }
            count = 1;
            rebound = 0; // it'll start counting again
        }
        samenumber = n2;
    }
    if (count > maxcount)
    {
        maxcount = count;
        maxindex = currindex;
    }
    printf("Pocetni indeks: %d\n", maxindex);
    printf("Duljina niza: %d", maxcount);
}