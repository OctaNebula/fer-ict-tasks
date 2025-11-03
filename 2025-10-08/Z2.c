#include <stdio.h>

int main()
{
    int a, b = 0;
    scanf("%d %d", &a, &b);
    if ((a > 100 && b < 100) || (a < 100 && b > 100))
    {
        printf("One number is greater than 100 and the other one isn't\n");
    }
    return 0;
}