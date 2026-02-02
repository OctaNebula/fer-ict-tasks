#include <stdio.h>
#include <string.h>

void pretvoriIzraz(char *izraz, char *rezultat)
{
    int lenght = strlen(izraz);
    int appendPosition = 0;

    for (int i = 0; i < lenght; i++)
    {
        if (izraz[i] >= 48 && izraz[i] <= 57)
        {
            rezultat[appendPosition] = izraz[i];
            appendPosition++;
        }
        else
        {
            switch (izraz[i])
            {
            case 43:
            {                                   // +
                rezultat[appendPosition] = ' '; // I could've used strcat but I'm going to take the safe and (boring) manual way to solve this
                appendPosition++;
                rezultat[appendPosition] = 'p';
                appendPosition++;
                rezultat[appendPosition] = 'l';
                appendPosition++;
                rezultat[appendPosition] = 'u';
                appendPosition++;
                rezultat[appendPosition] = 's';
                appendPosition++;
                rezultat[appendPosition] = ' ';
                appendPosition++;
                break;
            }
            case 42:
            {
                rezultat[appendPosition] = ' ';
                appendPosition++;
                rezultat[appendPosition] = 'p';
                appendPosition++;
                rezultat[appendPosition] = 'u';
                appendPosition++;
                rezultat[appendPosition] = 't';
                appendPosition++;
                rezultat[appendPosition] = 'a';
                appendPosition++;
                rezultat[appendPosition] = ' ';
                appendPosition++;
                break;
            }
            case 45:
            {
                rezultat[appendPosition] = ' ';
                appendPosition++;
                rezultat[appendPosition] = 'm';
                appendPosition++;
                rezultat[appendPosition] = 'i';
                appendPosition++;
                rezultat[appendPosition] = 'n';
                appendPosition++;
                rezultat[appendPosition] = 'u';
                appendPosition++;
                rezultat[appendPosition] = 's';
                appendPosition++;
                rezultat[appendPosition] = ' ';
                appendPosition++;
                break;
            }
            case 47:
            {
                rezultat[appendPosition] = ' ';
                appendPosition++;
                rezultat[appendPosition] = 'p';
                appendPosition++;
                rezultat[appendPosition] = 'o';
                appendPosition++;
                rezultat[appendPosition] = 'd';
                appendPosition++;
                rezultat[appendPosition] = 'i';
                appendPosition++;
                rezultat[appendPosition] = 'j';
                appendPosition++;
                rezultat[appendPosition] = 'e';
                appendPosition++;
                rezultat[appendPosition] = 'l';
                appendPosition++;
                rezultat[appendPosition] = 'j';
                appendPosition++;
                rezultat[appendPosition] = 'e';
                appendPosition++;
                rezultat[appendPosition] = 'n';
                appendPosition++;
                rezultat[appendPosition] = 'o';
                appendPosition++;
                rezultat[appendPosition] = ' ';
                appendPosition++;
                rezultat[appendPosition] = 's';
                appendPosition++;
                rezultat[appendPosition] = ' ';
                appendPosition++;
                break;
            }
            }
        }
    }
    rezultat[appendPosition] = '\0';
    return;
}

int main()
{
    char izraz[200 + 1];
    char rezultat[1000 + 1];

    printf("Unesite izraz> ");
    scanf("%s", izraz);

    pretvoriIzraz(izraz, rezultat);

    printf("Izlaz: %s\n", rezultat);

    return 0;
}