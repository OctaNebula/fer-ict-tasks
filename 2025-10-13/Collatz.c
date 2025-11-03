#include <stdio.h>

int main()
{
    long int number = 0;
    printf("Insert number -> ");
    scanf("%ld", &number);

    while (number != 1)
    {
        if (number % 2 == 0)
        {
            number = number / 2;
            printf("%ld\n", number);
        }
        else
        {
            number = (number * 3) + 1;
            printf("%ld\n", number);
        }
    }

    if (number == 1)
    {
        printf("Collatz Conjecture applies for this example.\n");
    }

    return 0;
}