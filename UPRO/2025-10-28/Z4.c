#include <stdio.h>

int main()
{
    printf("Unesite dimenzije polja: ");
    int size;

    scanf("%d", &size);
    int matrix[size][size];

    printf("Unesite elemente polja:\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    int newmatrix[size][size];

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            newmatrix[i][j] = matrix[j][i];
        }
    }

    int newnewmatrix[size][size];

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            newnewmatrix[i][j] = newmatrix[i][size - 1 - j];
        }
    }

    printf("Izracunato polje: \n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d", newnewmatrix[i][j]);
            if (j < size - 1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}