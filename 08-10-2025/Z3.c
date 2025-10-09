#include <stdio.h>

int main()
{
    int c2f = 0;
    float n = 0;

    printf("0 for C->F, 1 for F-C -> ");
    scanf("%d", &c2f);

    if (c2f == 0)
    {
        printf("\n x C -> F; ");
        scanf("%f", &n);
        n = n * 1.8 + 32;
    }
    else
    {
        printf("\n x F -> C; ");
        scanf("%f", &n);
        n = ((float)n - 32) / 1.8;
    }
    printf("%.2f", n);
    printf("\n");
    return 0;
}