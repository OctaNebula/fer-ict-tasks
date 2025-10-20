#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Upisite iznos u kn > ");
    int hrk = 0;
    scanf("%d", &hrk);

    int fives = 0;
    int twos = 0;
    int ones = 0;

    printf("Kovanice:\n");
    int lastdig = hrk % 10;
    if (lastdig > 5)
    {
        lastdig = lastdig - 5;
    }

    if (lastdig % 2 == 1)
    {
        lastdig = lastdig - 1;
        ones = 1;
    }

    twos = lastdig / 2;
    fives = hrk / 5;

    if (fives != 0)
    {
        printf("%d x 5 kn\n", fives);
    }
    if (twos != 0)
    {
        printf("%d x 2 kn\n", twos);
    }
    if (ones == 1)
    {
        printf("%d x 1 kn\n", ones);
    }
    return 0;
}