#include <stdio.h>
#include <stdlib.h>

int main()
{
    float *popisTransakcija = NULL;
    int total_count = 0;
    int n;
    printf("Unesite broj dana za koji zelite stvoriti popis transakcija: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Unesite broj transakcija provedenih prije %d dana: ", n - i);
        int num_transactions;
        scanf("%d", &num_transactions);
        int start_index = total_count; // Save where we are CURRENTLY
        total_count += num_transactions;

        popisTransakcija = realloc(popisTransakcija, total_count * sizeof(float));

        for (int j = 0; j < num_transactions; j++)
        {
            printf("Transakcija %d: ", j + 1);
            scanf("%f", &popisTransakcija[start_index + j]);
        }
    }

    printf("Popis transakcija:\n");
    float balance = 0;
    // Iterate from the last element (newest) down to 0 (oldest)
    for (int i = total_count - 1; i >= 0; i--)
    {
        printf("%.2f\n", popisTransakcija[i]);
        balance += popisTransakcija[i];
    }

    printf("Stanje racuna: %.2f\n", balance);

    // Always free memory!
    free(popisTransakcija);
    popisTransakcija = NULL;
}