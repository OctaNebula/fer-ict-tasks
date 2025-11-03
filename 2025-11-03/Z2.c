#include <stdio.h>

int main()
{
    int n;
    printf("Upisite broj redaka/stupaca matrice > ");
    scanf("%d", &n);
    int matrix[n][n];
    printf("Upisite %dx%d clanova > \n", n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("Upisite redni broj retka > ");
    int rows;
    scanf("%d", &rows);
    printf("Upisite redni broj stupca > ");
    int columns;
    scanf("%d", &columns);

    int s_rows = 0;
    int s_columns = 0;

    for (int i = 0; i < n; i++)
    {
        s_rows = s_rows + matrix[rows][i];
    }

    for (int i = 0; i < n; i++)
    {
        if (i != rows) // to prevent summing the shared int twice
        {
            s_columns = s_columns + matrix[i][columns];
        }
    }

    int sum = s_rows + s_columns;

    printf("Suma brojeva koji se nalaze u retku %d i stupcu %d je %d.", rows, columns, sum);
}