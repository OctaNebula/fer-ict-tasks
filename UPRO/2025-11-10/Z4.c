#include <stdio.h>

int main()
{
    unsigned short int n;
    printf("Unesite broj > ");
    scanf("%hu", &n);

    printf("Binarni zapis broja: ");
    for (int i = 15; i >= 0; i--)
    {
        printf("%d", ((n >> i) & 1));
    }
    printf("\n");

    int index, value;

    while (1)
    {
        printf("Unesite indeks i vrijednost bita > ");
        scanf("%d%d", &index, &value);
        if (index < 0 || index > 15 || value < 0 || value > 1)
        {
            break;
        }
        if (value == 1)
        {
            n |= (1 << index); // Set bit to 1
        }
        else
        {
            n &= ~(1 << index); // Clear bit to 0
        }

        // n = (n & ~(1 << index)) | (value << index); <- This can be used as a oneliner
    }

    printf("\nDekadski i binarni zapis izmijenjenog broja: %hu ", n);
    for (int i = 15; i >= 0; i--)
    {
        printf("%d", ((n >> i) & 1));
    }
}