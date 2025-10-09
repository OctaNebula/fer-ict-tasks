#include <stdio.h>

int main()
{
    int a, b = 0;
    scanf("%d %d", &a, &b);

    if (((a - b) < 100) || ((b % 2 == 1) && (b > 0))) //(!((a - b >= 100) && ((b % 2 == 0) || (b < 0))))
    {
        printf("True\n");
    }

    return 0;
}