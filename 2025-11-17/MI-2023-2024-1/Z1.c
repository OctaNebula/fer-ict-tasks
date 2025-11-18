#include <stdio.h>

int hasDigit(int n, int dig)
{
    int one, two, three;
    three = n / 100;
    two = (n - three * 100) / 10;
    one = n % 10;

    if (one == dig || two == dig || three == dig)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int sum = 0;
    int prime = 1;
    int digit;

    printf("Upisite znamenku > ");
    scanf("%d", &digit);

    for (int i = 999; i >= 100; i--)
    {
        prime = 1;
        for (int j = 2; j <= (i - 1); j++)
        {
            if (i % j == 0)
            {
                prime = 0;
            }
        }
        if (prime)
        {
            if (hasDigit(i, digit))
            {
                printf("%d ", i);
                sum += i;
            }
        }
    }
    printf("\nZbroj: %d", sum);
}