#include <stdio.h>

int main()
{
    int daysInput = 0;
    printf("Unesite broj dana > ");
    scanf("%d", &daysInput);

    int years = 0;
    int weeks = 0;
    int days = 0;

    while (daysInput != 0)
    {
        if (daysInput - 365 >= 0)
        {
            years = years + 1;
            daysInput = daysInput - 365;
        }
        else if (daysInput - 7 >= 0)
        {
            weeks = weeks + 1;
            daysInput = daysInput - 7;
        }
        else
        {
            days = daysInput;
            daysInput = 0;
        }
    }
    printf("Unos odgovara razdoblju od %d godina %d tjedana i %d dana\n", years, weeks, days);

    return 0;
}