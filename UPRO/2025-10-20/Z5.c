#include <stdio.h>

int main()
{
    int number = 0;
    int hit = 0;
    printf("Unesite broj > \n");
    scanf("%d", &number);
    if (number > 0 && number == (int)number)
    {
        if (number % 2 == 0)
        {
            printf("Broj je djeljiv s brojem 2.\n");
            hit = 1;
        }
        if (number % 3 == 0)
        {
            printf("Broj je djeljiv s brojem 3.\n");
            hit = 1;
        }
        if (number % 5 == 0)
        {
            printf("Broj je djeljiv s brojem 5.\n");
            hit = 1;
        }
        if (number % 7 == 0)
        {
            printf("Broj je djeljiv s brojem 7.\n");
            hit = 1;
        }
        if (hit == 0)
        {
            printf("Broj nije djeljiv s brojevima 2, 3, 5, 7.");
        }
    }
    else
    {
        printf("Unesen je pogresan broj!");
    }
    return 0;
}