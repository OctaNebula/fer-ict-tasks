#include <stdio.h>
#include <ctype.h>

int main()
{
    int checker;
    printf("Upisite znakovni niz > ");
    char string[150];
    fgets(string, sizeof(string), stdin);
    printf("Izlazni znakovni niz je : ");
    for (int i = 0; string[i] != '\0'; i++)
    {
        if isalpha (string[i])
        {
            printf("%c", string[i]);
            checker = 1;
        }
    }
    if (checker == 0)
    {
        printf("prazan string");
    }
    printf("\n");
}