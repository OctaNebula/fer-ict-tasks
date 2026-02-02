#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// OVDJE NAPISATI DEFINICIJU FUNKCIJE dodajGenRecenicu
// ok sure
// "NEMA MIJENJANJA POSTOJECEG KODA GRRRRRR" literally 1984
int size = 0; // le epic global variable
int charPos = 0;

char *dodajGenRecenicu(char *tekst, int lenght, int count)
{
    int alphabet = 0;

    // printf("before realloc: %lu\n", sizeof(tekst));

    size += (lenght * count + count); // not forgetting about spaces btw (as well as the .)
    tekst = realloc(tekst, size * sizeof(char));
    // printf("mem got realloc'd with size %d, size is now %lu\n", size, sizeof(tekst));

    if (tekst == NULL)
    {
        printf("haha loser");
        return NULL;
    }
    else
    {
        // printf("tekst = %lu, size = %d\n", sizeof(tekst), size);
    }

    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < lenght; j++)
        {
            tekst[charPos] = (char)(97 + alphabet % 26);
            // printf("Successfully appended %c at position %d.\n", (97 + alphabet % 26), charPos);
            charPos++;
            alphabet++;
        }
        if (i == (count - 1))
        {
            tekst[charPos] = '.';
            charPos++;
            // printf("Successfully appended %c at position %d.\n", '.', charPos);
        }
        tekst[charPos] = ' ';
        charPos++;
        // printf("Successfully appended %c at position %d.\n", ' ', charPos);
        if (i == (count - 1))
        {
            charPos++;
            break;
        }
    }

    return tekst;
}

void kontrolniIspis(char *tekst)
{
    int duljinaTeksta;
    duljinaTeksta = strlen(tekst);
    if (duljinaTeksta <= 60)
    {
        // ispisi cijeli tekst
        printf("%s\n\n", tekst);
    }
    else
    {
        // tekst je dulji od 60 znakova, pa ce se ispisati samo pocetak i kraj teksta
        printf("%.20s ... %s\n\n", tekst, tekst + duljinaTeksta - 20);
    }
}

int main(void)
{
    char *tekst;
    // printf("sizeof(tekst) = %lu", sizeof(tekst));
    int duljRijeci, brojRijeci;
    do
    {
        printf("Upisite broj rijeci > ");
        scanf("%d", &brojRijeci);
        if (brojRijeci < 1)
            break;
        printf("Upisite duljinu rijeci > ");
        scanf("%d", &duljRijeci);

        // OVDJE NAPISATI POZIV FUNKCIJE dodajGenRecenicu
        if (brojRijeci == 0)
        {
            break;
        }
        tekst = malloc(1000); // for some reason adding this line of code adds at least 1 output lol
        dodajGenRecenicu(tekst, duljRijeci, brojRijeci);

        kontrolniIspis(tekst);
    } while (1);
    return 0;
}