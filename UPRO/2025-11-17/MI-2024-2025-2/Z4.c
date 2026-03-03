#include <stdio.h>
#include <limits.h>

unsigned int row(unsigned int a, unsigned int b)
{
    int index = 0;
    int sindex = 0;
    int eindex = 0;
    int lenght = 0;
    int maxlenght = 0;
    int rebound = 0;

    for (int i = 0; i < 32; i++)
    {
        if (i > 0)
        { // to exclude i == 0;
            if (!((a >> i) ^ (b >> i)) && !((a >> (i - 1)) ^ (b >> (i - 1))))
            {
                lenght += 1;

                if (rebound == 0)
                {
                    index = i - 1;
                    rebound = 1;
                }
            }
            else
            {
                rebound = 0;
                if (lenght >= maxlenght)
                {
                    maxlenght = lenght;
                    eindex = i;
                    sindex = index;
                    lenght = 0;
                }
            }
        }
    }
    if (lenght >= maxlenght)
    {
        maxlenght = lenght;
        eindex = 32;
        sindex = index;
    }
    if (maxlenght == 0)
    {
        printf("Nema podudarnog slijeda.");
    }
    else
    {
        printf("Podudarni slijed:\n");
        for (int i = eindex - 1; i >= sindex; i--)
        {
            if ((a >> i) & 1)
            {
                printf("1");
            }
            else
            {
                printf("0");
            }
        }
    }
    return 0;
}

int main()
{
    unsigned int a, b;
    printf("Unesite dva broja > \n");
    scanf("%u%u", &a, &b);
    printf("1. i 2. broj binarno:\n");
    for (int i = 31; i >= 0; i--)
    {
        if ((a >> i) & 1)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
    printf("\n");
    for (int i = 31; i >= 0; i--)
    {
        if ((b >> i) & 1)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
    printf("\n");
    row(a, b);
}