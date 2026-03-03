#include <stdio.h>
int main()
{
    int value = 0;
    printf("Unesite pH vrijednost otopine > ");
    scanf("%d", &value);
    if (value > 14 || value < 0)
    {
        printf("KRIVI UNOS");
        return 0;
    }
    if (value > 7)
    {
        printf("Otopina je luznata.");
    }
    else if (value == 7)
    {
        printf("Otopina je neutralna.");
    }
    else
    {
        printf("Otopina je kisela.");
    }
    return 0;
}