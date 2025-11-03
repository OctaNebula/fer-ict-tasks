#include <stdio.h>

int main()
{
    printf("Upisite iznos u kn > ");
    int hrk = 0;
    scanf("%d", &hrk);

    int fives = 0;
    int twos = 0;
    int ones = 0;

    printf("Kovanice:\n");

    while (hrk != 0)
    {
        if (hrk - 5 >= 0)
        {
            hrk = hrk - 5;
            fives = fives + 1;
        }
        else if (hrk - 2 >= 0)
        {
            hrk = hrk - 2;
            twos = twos + 1;
        }
        else
        {
            hrk = hrk - 1;
            ones = ones + 1;
        }
    }

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