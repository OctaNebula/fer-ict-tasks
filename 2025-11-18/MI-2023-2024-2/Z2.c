#include <stdio.h>
#include <string.h>

int main()
{
    printf("Unesite prvi niz > ");
    char str1[20];
    fgets(str1, sizeof(str1), stdin);
    printf("Unesite drugi niz > ");
    char str2[20];
    fgets(str2, sizeof(str2), stdin);

    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    printf("Spojeni niz > ");

    printf("%s", str1);
    for (int i = 1; i < (int)(strlen(str2) + 1); i++)
    {
        printf("%c", str2[strlen(str2) - i]);
    }
}