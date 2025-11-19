// YE WHO ENTER HERE, ABANDON ALL HOPE

#include <stdio.h>
#include <limits.h>

struct counter
{
    unsigned short int value;
    unsigned short int count;
};

int main()
{
    unsigned short int n = 100, m = 100;
    while (!(n * m <= (unsigned short int)100))
    {
        printf("Unesite m i n: ");
        scanf("%hu%hu", &n, &m);
    }
    unsigned short int matrix[n][m];
    printf("Unesite elemente matrice:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%hu", &matrix[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        struct counter count[m];
        for (int j = 0; j < m; j++)
        {
            count[j].value = 0;
            count[j].count = 0;
        }
        int inside = 0;
        int structlen = 0;

        for (int j = 0; j < m; j++)
        {
            // check if it's inside
            inside = 0;
            for (int z = 0; z < m; z++)
            {
                if (matrix[i][j] == count[z].value)
                {
                    inside = 1;
                }
            }
            // if it's inside, find the value and append to it
            if (inside)
            {
                for (int z = 0; z < m; z++)
                {
                    if (matrix[i][j] == count[z].value)
                    {
                        inside = 1;
                        count[z].count++;
                    }
                }
            }

            // if not, add it

            if (!inside)
            {
                count[j].value = matrix[i][j];
                // printf("Added %d, i = %d, j = %d", matrix[i][j], i, j);
                count[j].count = 1;
                structlen++;
            }
        }
        /*
        printf("\n- Vals for row %d\n -", i);
        for (int j = 0; j < m; j++)
        {
            printf("Value: %hu, Count %hu\n", count[j].value, count[j].count);
        }
        */
        int max = INT_MIN;
        int modindex;

        for (int j = 0; j < structlen; j++) // finds the max mod
        {
            if (count[j].count >= max && count[j].value <= 255)
            {
                modindex = j;
                max = count[j].count;
            }
        }
        int maxval = INT_MIN;
        for (int j = 0; j < m; j++) // checks for vals with a greater val
        {
            if (count[j].count == max)
            {
                if (count[j].value > maxval)
                {
                    maxval = count[j].value;
                    modindex = j;
                    // printf("\nGreatest value is now %d", maxval);
                }
            }
        }
        printf("Redak %d: mod=%d\n", i + 1, count[modindex].value);
    }
}