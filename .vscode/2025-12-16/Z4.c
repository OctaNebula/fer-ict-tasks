#include <stdio.h>
#include <string.h>
#include <ctype.h>

void BrojSlovaZnamenaka(char *niz, int *brojSlova, int *brojZnamenaka)
{
    for (int i = 0; i < (strlen(niz)); i++)
    {
        if (isalpha((char)*(niz + i)))
        {
            (*brojSlova)++;
        }
        else if (isdigit(*(niz + i)))
        {
            (*brojZnamenaka)++;
        }
    }
}