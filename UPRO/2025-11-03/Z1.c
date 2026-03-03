#include <stdio.h>
int main()
{
    int m;
    printf("Upisite velicinu polja m > ");
    scanf("%d", &m);

    int array[m];
    int maxarray[m];
    int max = 0;
    int newmax = 0;
    long unsigned int maxcount = 0;

    printf("Upisite %d clanova polja m > ", m);
    for (int i = 0; i < m; i++)
    {
        int n;
        scanf("%d", &n);
        array[i] = n;
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = i; j < m; j++)
        {
            newmax = 0;
            for (int k = i; k <= j; k++)
            {
                newmax = newmax + array[k];
            }

            if (newmax > max)
            {
                int count = 0;
                for (int k = i; k <= j; k++)
                {
                    maxarray[count] = array[k];
                    count = count + 1;
                    maxcount = count;
                }
                max = newmax;
            }
        }
    }
    printf("Pronadjeno pod-polje:");
    for (long unsigned int i = 0; i < maxcount; i++)
    {
        printf(" %d", maxarray[i]);
    }
    printf("\nNajveca suma kontinuiranog pod-polja je: %d", max);
}