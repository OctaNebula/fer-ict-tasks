#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char string[200];
    printf("Upisite znakovni niz > ");
    fgets(string, sizeof(string), stdin);

    int len = strlen(string);

    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == '\n')
        {
            string[i] = '\0';
            break;
        }
    }

    printf("Obrnuti niz: ");
    for (int i = len - 1; i >= 0; i--)
    {
        printf("%c", toupper(string[i]));
    }
    printf("\n");

    return 0;
}