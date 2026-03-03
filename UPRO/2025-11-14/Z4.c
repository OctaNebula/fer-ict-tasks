#include <stdio.h>

unsigned int reverse(unsigned int n)
{
    unsigned int blank = 0;
    for (int i = 31; i >= 0; i--)
    {
        if ((n >> i) & 1)
        {
            blank |= (1 << (31 - i));
        }
    }

    return blank;
}

int main()
{
    int n;
    printf("Unesite broj > ");
    scanf("%d", &n);
    printf("\n");

    printf("Broj binarno: ");
    for (int i = 31; i >= 0; i--)
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

    int reversed;
    reversed = reverse(n);

    printf("\nObrnuti binarno: ");

    for (int i = 31; i >= 0; i--)
    {
        if ((reversed >> i) & 1)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }

    printf("\nObrnuti dekadski: %u", reversed);

    return 0;
}