#include <stdio.h>

int djelitej(int a, int b)
{
    int tempval = 0;
    while (b != 0)
    {
        tempval = b;
        b = a % b;
        a = tempval;
    }
    return a; // Return the GCD
}

void reduciraj(int *a, int *b) // Use pointers to modify original values
{
    int gcd = djelitej(*a, *b);
    *a = *a / gcd; // Modify the value at the address
    *b = *b / gcd; // Modify the value at the address
}

int main()
{
    printf("Upisite brojnik i nazivnik: ");
    int num, den;
    scanf("%d%d", &num, &den);
    printf("Razlomak: %d/%d\n", num, den);

    reduciraj(&num, &den); // Pass addresses with &
    if (den != 1)
    {
        printf("Reduciran: %d/%d", num, den);
    }
    else
    {
        printf("Reduciran: %d", num);
    }
    return 0;
}