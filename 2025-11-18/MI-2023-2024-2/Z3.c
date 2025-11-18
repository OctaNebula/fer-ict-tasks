#include <stdio.h>

int main()
{
    int n = 0;
    while (!((n >= 2) && (n <= 10)))
    {
        printf("Ucitajte red matrice> ");
        scanf("%d", &n);
    }

    int matrix[n][n];

    printf("Ucitajte %d elemenata cjelobrojne matrice> ", n * n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Ucitana matrica:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Posmaknuta matrica:\n");

    int temp = matrix[0][0];

    int j = 0;
    while (j < n - 1)
    {
        matrix[0][j] = matrix[0][j + 1];
        j++;
    }

    int i = 0;
    while (i < n - 1)
    {
        matrix[i][n - 1] = matrix[i + 1][n - 1];
        i++;
    }

    j = n - 1;
    while (j > 0)
    {
        matrix[n - 1][j] = matrix[n - 1][j - 1];
        j--;
    }

    i = n - 1;
    while (i > 1)
    {
        matrix[i][0] = matrix[i - 1][0];
        i--;
    }

    matrix[1][0] = temp;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
