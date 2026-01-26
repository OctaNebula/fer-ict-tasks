#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

struct pravokutnik
{
    int x1;
    int y1;
    int x2;
    int y2;
};

struct pravokutnik rjesenje;

void nadiNajveciOpseg(int n, struct pravokutnik *pravokutnici)
{
    int max_opseg = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int width = abs(pravokutnici[i].x2 - pravokutnici[i].x1);
        int height = abs(pravokutnici[i].y2 - pravokutnici[i].y1);
        int perimiter = 2 * (width + height);

        if (perimiter > max_opseg)
        {
            rjesenje = pravokutnici[i];
            max_opseg = perimiter;
        }
    }
}