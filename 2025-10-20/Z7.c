#include <stdio.h>
int main()
{
    int n = 0;
    printf("Unesite broj rijeci brojalice > ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("KRIVI UNOS");
        return 0;
    }

    for (int i = 1; i < (n + 1); i++)
    {
        if (i % 3 == 1)
        {
            printf("eci ");
        }
        if (i % 3 == 2)
        {
            printf("peci ");
        }
        if (i % 3 == 0)
        {
            printf("pec ");
        }
    }
}