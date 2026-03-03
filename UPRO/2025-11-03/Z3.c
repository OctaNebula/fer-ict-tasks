#include <stdio.h>

int main()
{
    int n;
    printf("Unesite n > ");
    scanf("%d", &n);
    int matrix[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Rezultat >");
    for (int i = 0; i < n; i++)
    {
        int sum1 = 0;
        int sum2 = 0;

        if (i != n - 1)
        {
            for (int j = 0; j < n; j++)
            {
                sum1 = sum1 + matrix[j][i];
                sum2 = sum2 + matrix[j][i + 1];
            }
        }
        else
        {
            for (int j = 0; j < n; j++)
            {
                sum1 = sum1 + matrix[j][i];
                sum2 = sum2 + matrix[j][0];
            }
        }
        printf(" %d", (sum1 - sum2));
    }
    printf("\n");
}