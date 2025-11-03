#include <stdio.h>

int main() // Z6 is literally Z4 but with the vec- ok whatever you get the idea
{
    int n, m, idxi, idxj;
    printf("Upisite brojeve N, M, idxi i idxj > ");
    scanf("%d %d %d %d", &n, &m, &idxi, &idxj);
    int matrix[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = 0;
        }
    }

    // РИКОШЕТ!!!

    int dx = 1, dy = 1;
    int steps = 0;

    while (1)
    {
        steps++;
        if (steps > 10000)
        {
            printf("Breaking after 10000 steps\n");
            break;
        }

        matrix[idxi][idxj] = 1;

        int next_i = idxi + dx;
        int next_j = idxj + dy;

        // Check if next position would hit a wall or go out of bounds
        int hit_top = (next_i < 0);
        int hit_bottom = (next_i >= n);
        int hit_left = (next_j < 0);
        int hit_right = (next_j >= m);

        if (hit_top || hit_bottom)
        {
            dx = -dx; // Flip vertical direction
        }
        if (hit_left || hit_right)
        {
            dy = -dy; // Flip horizontal direction
        }

        // Calculate final next position after reflections
        next_i = idxi + dx;
        next_j = idxj + dy;

        // Check if final next position has a 1 (already visited)
        if (next_i >= 0 && next_i < n && next_j >= 0 && next_j < m && matrix[next_i][next_j] == 1)
        {
            break;
        }

        idxi = next_i;
        idxj = next_j;

        // safety check
        if (idxi < 0)
            idxi = 0;
        if (idxi >= n)
            idxi = n - 1;
        if (idxj < 0)
            idxj = 0;
        if (idxj >= m)
            idxj = m - 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("Duljina: %d\n", steps);
}