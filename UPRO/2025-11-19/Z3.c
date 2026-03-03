#include <stdio.h>
void selection_sort(int arr[], int size) // ill need this later...
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_idx = i;

        // max element
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }

        // zamjeni s prvim
        if (min_idx != i)
        {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}
int main()
{
    printf("Unos podataka:\n");
    int averages[50];
    int temparray[10];
    int breakage = 0;
    int max;

    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            scanf("%d", &temparray[j]);
            if (temparray[j] == 0)
            {
                breakage = 1;
                break;
            }
        }
        if (breakage)
        {
            break;
        }
        }
}