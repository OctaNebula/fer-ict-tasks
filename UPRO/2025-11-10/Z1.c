#include <stdio.h>

int main()
{
    unsigned short int n;
    printf("Unesite broj > ");
    scanf("%hu", &n);
    printf("Binarni zapis ucitanog broja: ");

    for (int i = 15; i > -1; i--)
    {
        if ((n >> i) & 1) // the if statement...

        /* NOTE TO SELF - HOW THIS WORKS;
            basically the integer n gets shifted i times
            which brings the bit we're targetting to the right.
            Then you compare it with & 1 which is 00...01 (in other
            words, the only the rightmost bit stays relevant) and
            you get either 1 or 0 as a result of passing it through
            the AND operator. Also do NOT mix the bitwise AND (&)
            and logical AND (&&), they ain't the same thing.
        */

        { // ...continues here.
            printf("1");
        }
        else
        {
            printf("0");
        }
    }

    if (n == 0)
    {
        printf("\nNema bita s vrijednosti 1.");
        return 0;
    }

    for (int i = 15; i > -1; i--)
    {
        if ((n >> i) & 1)
        {
            printf("\nIndeks najznacajnijeg bita s vrijednosti 1: %d", i);
            break;
        }
    }
}