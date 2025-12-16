#include <stdio.h>
#include <string.h>
#include <ctype.h>

int ProvjeriLozinku(char *password, int *brVelikih, int *brBrojeva, int *brSpec)
{
    for (int i = 0; i < (strlen(password)); i++)
    {
        if (isupper(*(password + i)))
        {
            (*brVelikih)++;
        }
        else if (isdigit(*(password + i)))
        {
            (*brBrojeva)++;
        }
        else if (islower(*(password + i)))
        {
        }
        else
        {
            (*brSpec)++;
        }
    }
}

int main()
{
    char string[11];
    printf("Upisite lozinku > \n");
    scanf("%s", string);
    if (strlen(string) < 10)
    {
        printf("Lozinka je prekratka!\n");
        // printf("%s, %d", string, strlen(string));
        return 0;
    }
    int velikih = 0;
    int brojevi = 0;
    int spec = 0;
    int dobra = 1;

    ProvjeriLozinku(string, &velikih, &brojevi, &spec);
    if (velikih < 2)
    {
        printf("Nema dovoljno velikih slova!\n");
        dobra = 0;
    }
    if (brojevi < 2)
    {
        printf("Nema dovoljno brojeva!\n");
        dobra = 0;
    }
    if (spec == 0)
    {
        printf("Nema dovoljno specijalnih znakova!\n");
        dobra = 0;
    }
    if (dobra == 1)
    {
        printf("Lozinka je ispravna!\n");
    }
}