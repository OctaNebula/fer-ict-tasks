#include <stdio.h>
int main()
{
    printf("Unesite broj clanova polja:");
    int n;
    scanf("%d", &n);
    printf("\nUnesite clanove polja (%d):", n);
    int field[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &field[i]);
    printf("\nUnesite vrijednost novog clana te indeks:");
    int new, inx;
    scanf("%d %d", &new, &inx);
    printf("\nPocetno polje\n");
    for (int i = 0; i < n; i++)
        printf("%d ", field[i]);
    printf("\nNovodobiveno polje\n");

    for (int i = n - 1; i > inx; i--)
    {
        field[i] = field[i - 1];
    }

    field[inx] = new;

    for (int i = 0; i < n; i++)
        printf("%d ", field[i]);
    return 0;
}