#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 1. SEEDING (Run ONCE in main)
void init_random()
{
    // Uses current time as seed.
    // Requires <time.h> and <stdlib.h>
    srand((unsigned int)time(NULL));
}

// 2. BASIC RANGE [0 to N-1]
int rand_zero_to_n(int n)
{
    // Returns 0, 1, ..., n-1
    return rand() % n;
}

// 3. SPECIFIC RANGE [Min to Max] (Inclusive)
int rand_range(int min, int max)
{
    // Formula: rand() % (Range Size) + Shift
    // Count of numbers = max - min + 1
    return rand() % (max - min + 1) + min;
}

// 4. RANDOM FLOAT [0.0 to 1.0]
float rand_float_0_1()
{
    // Divide by RAND_MAX
    return (float)rand() / (float)RAND_MAX;
}

// 5. RANDOM FLOAT [Min to Max]
float rand_float_range(float min, float max)
{
    float scale = rand_float_0_1(); // 0.0 to 1.0
    return min + scale * (max - min);
}

// 6. RANDOM ARRAY FILL
void fill_random_array(int *arr, int size, int min, int max)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand_range(min, max);

        // Check for duplicates here if needed
    }
}

// 7. RANDOM STRING (e.g., A-Z)
void rand_string(char *str, int length)
{
    // ASCII 'A' is 65, 'Z' is 90
    // Range size: 26
    for (int i = 0; i < length; i++)
    {
        str[i] = (rand() % 26) + 'A';
    }
    str[length] = '\0'; // Don't forget terminator
}

// 8. SHUFFLE ARRAY (Fisher-Yates)
void shuffle(int *arr, int n)
{
    if (n > 1)
    {
        for (int i = n - 1; i > 0; i--)
        {
            int j = rand() % (i + 1);
            // Swap arr[i] with arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
}
