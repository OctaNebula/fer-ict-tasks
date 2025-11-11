#include <stdio.h>
#include <math.h>

int savrsen_kvadrat(int n)
{
    double root = sqrt(n);
    if (root == (int)root)
    {
        return 1;
    }
    return 0;
}

int factorial(int n)
{
    return tgamma(n + 1);
}

int zbroj_znamenaka(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum = sum + (n % 10);
        n = n / 10;
    }
    return sum;
}

int main()
{
    int n;
    printf("Upisite prirodni broj > ");
    scanf("%d", &n);
    int endval = savrsen_kvadrat(zbroj_znamenaka(factorial(n)));
    if (endval == 1)
    {
        printf("Suma znamenaka od %d! je savrsen kvadrat.", n);
    }
    else
    {
        printf("Suma znamenaka od %d! nije savrsen kvadrat.", n);
    }
}