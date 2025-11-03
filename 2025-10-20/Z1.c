#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number = 0;
    printf("Unesite cetveroznamenkasti broj > ");
    scanf("%d", &number);
    // printf("\n");
    int kilo = number / 1000;
    int hecta = (number / 100) % 10;
    int deca = (number / 10) % 10;
    int prima = number % 10;
    if (kilo + deca == hecta + prima)
    {
        printf("Provjera je uspjesna!\n");
    }
    else
    {
        int result = abs((kilo + deca) - (hecta + prima));
        printf("Apsolutna razlika suma je %d\n", result);
    }
    return 0;
}