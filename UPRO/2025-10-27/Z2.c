#include <stdio.h>

int main()
{
    int n;
    printf("Lenght of the fibonacci series: ");
    scanf("%d", &n);
    int fibonacciArray[n];
    fibonacciArray[0] = 1;
    fibonacciArray[1] = 2;
    for (int i = 2; i < n; i++)
    {
        fibonacciArray[i] = fibonacciArray[i - 1] + fibonacciArray[i - 2];
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", fibonacciArray[i]);
    }
}