#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int n;
    int min = INT_MAX;
    printf("upisite velicinu polja > ");
    scanf("%d", &n);
    int arr[n];
    printf("upisite elemente polja > ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (abs(arr[i] - arr[j]) < min)
            {
                min = abs(arr[i] - arr[j]);
            }
        }
    }

    printf("najmanji razmak: %d\n", min);

    int nmins = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (abs(arr[i] - arr[j]) == min)
            {
                nmins += 1;
            }
        }
    }

    printf("broj parova: %d", nmins);
}