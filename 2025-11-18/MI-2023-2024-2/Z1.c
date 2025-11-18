#include <stdio.h>

int main()
{
    int n = 0;
    while (!(n > 2))
    {
        printf("Unesite n > ");
        scanf("%d", &n);
    }
    int array[n];

    printf("Unesite clanove niza > ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    int d = array[1] - array[0];
    int truth = 1;

    for (int i = 1; i < n - 1; i++)
    {
        if (!((array[i + 1] - array[i]) == d))
        {
            truth = 0;
        }
    }
    if (truth == 1)
    {
        printf("A > %d", d);
    }
    else
    {
        printf("NIJE");
    }
}