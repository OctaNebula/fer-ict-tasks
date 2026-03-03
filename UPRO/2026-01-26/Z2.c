#include <stdio.h>
#include <stdlib.h>

void printarray(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", array[i]);
    }
}

int main()
{
    int *arr1, *arr2;
    arr1 = malloc(5 * sizeof(int));
    printf("Junk data;\n");
    printarray(arr1, 5);
    free(arr1);
    printf("Zeros;\n");
    arr2 = calloc(5, sizeof(int));
    printarray(arr2, 5);
}