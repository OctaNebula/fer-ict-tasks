#include <stdio.h>
#include <math.h>

void sumaPotencija(int a, int b, int c, int n, int *rez1, int *rez2)
{
    int sum1 = 0;
    int sum2 = 0;

    sum1 += pow(a, n) + pow(b, n) + pow(c, n);
    // printf("%d ", sum1);
    sum2 += pow((a + b + c), n);

    *rez1 = sum1;
    *rez2 = sum2;
}