#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

_Bool check(int *notarray, int n, int *first, int *last, int repeats)
{
    int numcheck = *(notarray + n - 1);
    int counter = 0;
    int repeatval = 0;

    for (int i = 0; i < n; i++)
    {
        if (numcheck == *(notarray + i))
        {
            counter++;
            repeatval = *(notarray + i);
        }
    }
    if (counter == repeats)
    {
        *first = 0;
        *last = repeatval / repeats;
        return true;
    }
    return false;
}

int main()
{
    int *notarray = NULL;
    int A, C, M, n;
    int first, last;
    printf("Upisite cijele brojeve A, C, M, n > ");
    scanf("%d%d%d%d", &A, &C, &M, &n);
    int x = 0;
    int iter = 1;

    notarray = realloc(notarray, sizeof(int)); // this is not an array and I won't be using it as one trust me bro
    *(notarray + iter - 1) = x;

    if (n > 1)
    {
        do
        {
            // 1. increase the size of the totally-not-an-array
            iter++;
            // printf("DEBUG: Increased iter size to %d\n", iter);
            notarray = realloc(notarray, iter * sizeof(int));
            // printf("DEBUG: Increased array size\n");
            // 2. calc the next element of the set

            x = ((A * x + C) % M); // btw x will always be equal to the last one ez
            // printf("DEBUG: Calculated new x: %d\n", x);
            // 3. add the new element to the conveniently defined integer (not an array)

            *(notarray + iter - 1) = x;
            // printf("DEBUG: Appended %d to index %d in array\n", x, iter - 1);
            // 4. repeat!
            // printf("-- DEBUG: Array --\n");
            // for (int i = 0; i < iter - 1; i++)
            // {
            //     printf("%d ", notarray[i]);
            // }

        } while (!check(notarray, iter, &first, &last, n));
    }

    // printf("ok I broke out: %d, %d\n", first, last);
    // printf("-- DEBUG: Array --\n");
    // for (int i = 0; i < iter; i++)
    // {
    //     printf("%d ", notarray[i]);
    // }

    printf("Vrijednost zadnjeg clana nalazi se na indeksima:");
    for (int i = 0; i < iter; i++)
    {
        // Check if the value at index i matches the last generated number (x)
        if (*(notarray + i) == x)
        {
            printf(" %d", i);
        }
    }

    free(notarray);

    return 0; // standard practice
}