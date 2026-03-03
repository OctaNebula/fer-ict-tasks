#include <stdio.h>
#include <limits.h>

int main()
{
    int n;
    int max = INT_MIN;
    int max_pos;
    int min = INT_MAX;
    int min_pos;
    printf("Upisi kapacitet (velicinu) polja > ");
    scanf("%d", &n);
    int array[n];
    printf("Upisi %d brojeva 0-9 > ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
            max_pos = i;
        }
        if (array[i] < min)
        {
            min = array[i];
            min_pos = i;
        }
    }

    if (min_pos < max_pos)
    {
        for (int i = min_pos; i < max_pos + 1; i++)
        {
            printf("%d", array[i]);
        }
    }
    if (min_pos > max_pos)
    {
        for (int i = min_pos; i >= max_pos; i--)
        {
            printf("%d", array[i]);
        }
    }
}