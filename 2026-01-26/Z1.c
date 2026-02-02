#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("How many numbers? > ");
    scanf("%d", &n);
    int *arr;
    arr = malloc(n * sizeof(int));
    if (arr == NULL)
    {
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
    free(arr);
}