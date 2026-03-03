#include <stdio.h>

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8};

    printf("%d", array[0]);

    // ok so this is how arrays work in C
    // I also assume I can modify the values

    array[0] = 2025;
    printf("%d", array[0]);

    // good
    // looks like I can also create empty arrays of any size

    int anotherArray[10];

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", anotherArray[i]); // this is an empty array
    }

    for (int i = 0; i < 10; i++)
    {
        anotherArray[i] = i + 1;
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", anotherArray[i]); // should now be filled with ascending numbers
    }
    return 0; // aight cool let's do some more interesting stuff
}