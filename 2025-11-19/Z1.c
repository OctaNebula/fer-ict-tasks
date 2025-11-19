#include <stdio.h>
int main()
{
    printf("Upisite clanove a1 i b1 > ");
    float a1, b1;
    scanf("%f%f", &a1, &b1);
    printf("Upisite maksimalni broj clanova > ");
    int n;
    scanf("%d", &n);

    float b2 = a1;
    float a2 = b1;

    float previous1_a = a2;
    float previous2_a = a1;

    float previous1_b = b2;
    float previous2_b = b1;

    float currenta;
    float currentb;

    printf("a( 1) =   %.2f, b( 1) =   %.2f;\n", a1, b1);
    if (b1 < 0)
    {
        return 0;
    }
    printf("a( 2) =   %.2f, b( 2) =   %.2f", a2, b2);

    if (b2 > 0)
    {
        printf(";\n");
    }

    for (int i = 0; i < n - 2; i++)
    {
        if (b2 < 0)
        {
            break; // BREAK FFS
        }
        currenta = (10.0 / 9.0) * previous1_a - (1.0 / 12.0) * previous2_b + 5;
        currentb = (2.0 / 3.0) * previous1_b - (1.0 / 19.0) * previous2_a + 1.0;
        printf("a(%2d) =   %.2f, b(%2d) =   %.2f", i + 3, currenta, i + 3, currentb);
        if (!(currentb < 0 || i == n - 2))
        {
            printf(";\n");
        }
        if (currentb < 0)
        {
            break;
        }

        previous2_a = previous1_a;
        previous1_a = currenta;
        previous2_b = previous1_b;
        previous1_b = currentb;
    }
}