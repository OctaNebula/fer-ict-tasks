#include <stdio.h>
#include <limits.h>

void getMinMax(int *array, int len, int *pmin, int *pmax)
{

    int min = INT_MAX;
    int max = INT_MIN;

    for (int i = 0; i < len; i++)
    {
        if (min >= *(array + i))
        {
            min = *(array + i);
        }
        if (max <= *(array + i))
        {
            max = *(array + i);
        }
    }
    *pmin = min;
    *pmax = max;
}