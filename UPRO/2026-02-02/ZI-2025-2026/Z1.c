#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void generiraj_vektor(double *vektor, int n)
{
    for (int i = 0; i < n; i++)
    {
        vektor[i] = (double)rand() / (double)RAND_MAX;
    }

    return;
}

double euclideanSimilarity(double *a, double *b, int n) // last stretch
{
    double result = 0;
    double numerator = 0;
    double denominatorLeft = 0;
    double denominatorRight = 0;

    for (int i = 0; i < n; i++)
    {
        numerator += a[i] * b[i];
    }

    for (int i = 0; i < n; i++)
    {
        denominatorLeft += pow(a[i], 2);
    }

    for (int i = 0; i < n; i++)
    {
        denominatorRight += pow(b[i], 2);
    }

    result = (numerator) / (sqrt(denominatorLeft) * sqrt(denominatorRight));

    return result;
}

int main()
{
    int n;
    printf("Unesite dimenziju vektora: ");
    scanf("%d", &n);

    double a[n], b[n];

    srand(500U);

    generiraj_vektor(a, n);
    generiraj_vektor(b, n);

    // ispis vektora
    printf("\nVektor 1: ");
    for (int i = 0; i < n; i++)
        printf("%.2f ", a[i]);

    printf("\nVektor 2: ");
    for (int i = 0; i < n; i++)
        printf("%.2f ", b[i]);
    printf("\n");

    // definicija potrebnih varijabli i računanje euklidske sličnosti
    double euklidskaSlicnost = euclideanSimilarity(a, b, n);

    printf("Euklidska slicnost: %.2f\n", euklidskaSlicnost);

    return 0;
}