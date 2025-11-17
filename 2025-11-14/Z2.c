#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;

    printf("Upisite red n > ");
    scanf("%d", &n);
    printf("Upisite elemente >\n");

    int matrix[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    int max = -__INT_MAX__;
    int maxi, maxj;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sum, l = 0, r = 0;
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                l = matrix[i - 1][j - 1];
            }
            if (i - 1 >= 0 && j + 1 < n)
            {
                r = matrix[i - 1][j + 1];
            }

            sum = matrix[i][j] + r + l;

            if (sum >= max)
            {
                max = sum;
                maxi = i;
                maxj = j;
            }
        }
    }

    printf("Najveci zbroj gornje-dijagonalnih elemenata je %d za element (%d, %d)", max, maxi, maxj);
}