#include <stdio.h>

int main()
{
    unsigned short int n;
    printf("Unesite broj > ");
    scanf("%hu", &n);
    printf("Binarni zapis ucitanog broja: ");

    for (int i = 15; i > -1; i--)
    {
        if ((n >> i) & 1)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }

    int detector = 0;

    for (int i = 0; i < 16; i++) // Start from 0, go up to 15
    {
        if (((n >> i) & 1) == 0) // Check if bit equals 0
        {
            printf("\nIndeks najmanje znacajnog bita s vrijednosti 0: %d", i);
            detector = 1;
            break;
        }
    }
    if (detector == 0)
    {
        printf("\nNema bita s vrijednosti 0.");
    }
}