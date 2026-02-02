#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0;
    int count = 0;
    int *arr = NULL;
    do
    {
        count += 1;
        arr = realloc(arr, count * sizeof(int));
        if (arr == NULL)
        {
            return 1;
        }
        scanf("%d", &n);
        arr[(count - 1)] = n;
    } while (n != -1);

    for (int i = 0; i < count; i++)
    {
        printf("%d", arr[i]);
    }
    free(arr);
}