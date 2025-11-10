#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float median(float a, float b, float c)
{
    float median;
    if ((a > b && a < c) || (a < b && a > c))
    {
        median = a;
    }
    else if ((b > a && b < c) || (b < a && b > c))
    {
        median = b;
    }
    else
    {
        median = c;
    }
    return fabs((float)(a + b + c) / 3 - median);
}

int main()
{
    float a, b, c;
    printf("Upisite tri realna broja > ");
    scanf("%f%f%f", &a, &b, &c);
    printf("Apsolutna vrijednost razlike mediana i srednje vrijednosti je: %.3f", median(a, b, c));
}