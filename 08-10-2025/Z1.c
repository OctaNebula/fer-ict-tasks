#include <stdio.h>
#include <math.h>
#define PI 3.141592653589793238462643383279502884

int main()
{
    long double r = 0;
    long double out;

    printf("Enter sphere radius > ");
    scanf("%Lf", &r);

    if (r > 0)
    {
        out = (4.0 / 3.0) * pow(r, 3) * PI;
        printf("Sphere volume = %.2Lf\n", out);
    }
    else
    {
        printf("Incorrect radius\n");
    }

    return 0;
}