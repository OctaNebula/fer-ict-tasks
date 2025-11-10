#include <stdio.h>

int main()
{
    unsigned short int n, m;
    printf("Unesite dva broja > ");
    scanf("%hu%hu", &n, &m);
    printf("Hammingova udaljenost: ");

    int hamming = 0;

    for (int i = 15; i >= 0; i--)
    {
        if (((n >> i) & 1) ^ ((m >> i) & 1))
        {
            hamming = hamming + 1;
        }
    }

    printf("%d", hamming);
}