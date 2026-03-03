#include <stdio.h>
#include <string.h>

int main()
{
    printf("Unesite niz > ");
    char string[50];
    int ascii_array[128] = {0}; // Initialize to 0
    fgets(string, sizeof(string), stdin);

    for (int i = 0; i < (int)strlen(string); i++)
    {
        if (string[i] != '\n')
        {
            ascii_array[(unsigned char)string[i]]++;
        }
    }

    int checkforsinglewin = 2;
    int max = -1;

    for (int i = 0; i < 128; i++) // finds max amount
    {
        if (ascii_array[i] > 0 && ascii_array[i] > max)
        {
            max = ascii_array[i];
        }
    }

    for (int i = 0; i < 128; i++) // checks if more than 1 element has max amount
    {
        if (ascii_array[i] == max)
        {
            checkforsinglewin--; // ideally this should get looped only once and set to 1
        }
    }

    if (checkforsinglewin == 1)
    {
        printf("Znak");
        for (int i = 0; i < 128; i++) // prints max amount
        {
            if (ascii_array[i] == max)
            {
                printf(" \"%c\" se ponavlja %d puta.\n", i, max);
            }
        }
    }
    else
    {
        printf("Znakovi");
        for (int i = 0; i < 128; i++) // in the case there are multiple maxes
        {
            if (ascii_array[i] == max)
            {
                printf(" \"%c\"", i);
                if (checkforsinglewin < 1)
                {
                    printf(",");
                    checkforsinglewin++; // recycling checkforsinglewin because why the fuck not lol
                }
            }
        }
        printf(" se ponavljaju %d puta.\n", max);
    }
}