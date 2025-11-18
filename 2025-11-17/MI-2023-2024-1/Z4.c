#include <stdio.h>

int main()
{
    int n = 11;
    int pos = 0;
    int neg = 0;

    while (!(n > 0 && n <= 10))
    {
        printf("Ucitajte red matrice> \n");
        scanf("%d", &n);
    }

    int matrix[n][n];

    printf("Ucitajte %d elemenata cjelobrojne matrice> ", n * n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] > 0)
            {
                pos += 1;
            }
            else if (matrix[i][j] < 0)
            {
                neg += 1;
            }
        }
    }

    int newmatrix[n][n]; // snippet shamelessly stolen from /2025-10-28/Z4.c

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            newmatrix[i][j] = matrix[j][i];
        }
    }

    int newnewmatrix[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            newnewmatrix[i][j] = newmatrix[n - 1 - i][j];
        }
    }

    printf("Ucitana matrica:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d", matrix[i][j]);
            if (j < n - 1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("Matrica rotirana ulijevo:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d", newnewmatrix[i][j]);
            if (j < n - 1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("Pozitivnih: %d", pos);
    printf("\nNegativnih: %d", neg);
}