#include <stdio.h>
#include <math.h>

double e_approx(int n)
{
    double e = 0;
    for (int i = 0; i <= n; i++)
    {
        e = e + ((double)1 / tgamma(i + 1));
    }
    return e;
}

int main()
{
    int n;
    printf("Upisite broj n: ");
    scanf("%d", &n);
    double a = e_approx(n);
    printf("Aproksimacija e: %.12lf\n", a);
    printf("Razlika: %.12lf", a - exp(1));

    return 0;
}