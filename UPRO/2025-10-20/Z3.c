#include <stdio.h>
int main()
{

    printf("Upisite troznamenkasti prirodni broj > ");
    int number = 0;
    scanf("%d", &number);

    int hecta = (number / 100);
    int deca = (number / 10) % 10;
    int prima = number % 10;

    int even = 0;
    int odd = 0;

    if (hecta % 2 == 0)
    {
        even = even + hecta;
    }
    else
    {
        odd = odd + hecta;
    }

    if (deca % 2 == 0)
    {
        even = even + deca;
    }
    else
    {
        odd = odd + deca;
    }

    if (prima % 2 == 0)
    {
        even = even + prima;
    }
    else
    {
        odd = odd + prima;
    }

    int result = even - odd;

    printf("Rezultat: %d\n", result);

    return 0;
}