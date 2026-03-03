#include <stdio.h>
#include <stdlib.h>

// 1. BASIC POINTER USAGE
void basic_pointers()
{
    int x = 10;
    int *p = &x; // Store address of x

    *p = 20;         // Change value of x via pointer
    printf("%d", x); // Prints 20
}

// 2. PASS BY REFERENCE (Modifying function arguments)
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 3. POINTER ARITHMETIC (Iterating arrays)
void array_traversal(int *arr, int size)
{
    // Access via index: arr[i]
    // Access via arithmetic: *(arr + i)
    for (int i = 0; i < size; i++)
    {
        printf("%d ", *(arr + i));
    }
}

// 4. DYNAMIC MEMORY (MALLOC - Garbage values)
int *create_dynamic_array(int size)
{
    // Allocate memory
    int *arr = (int *)malloc(size * sizeof(int));

    // Always check for NULL
    if (arr == NULL)
        return NULL;

    return arr;
}

// 5. DYNAMIC MEMORY (CALLOC - Zero initialized)
int *create_zero_array(int size)
{
    // Allocates AND sets all bits to 0
    int *arr = (int *)calloc(size, sizeof(int));
    if (arr == NULL)
        return NULL;
    return arr;
}

// 6. RESIZING MEMORY (REALLOC)
int *resize_array(int *old_arr, int new_size)
{
    // Tries to extend memory. If fails, returns NULL but old_arr is still valid.
    // If successful, data is moved to new location.
    int *new_arr = (int *)realloc(old_arr, new_size * sizeof(int));
    if (new_arr == NULL)
    {
        // Handle error, maybe free old_arr or keep it
        return NULL;
    }
    return new_arr;
}

// 7. DOUBLE POINTERS (Dynamic 2D Arrays / Array of Strings)
void double_pointers()
{
    int rows = 3, cols = 4;

    // Step 1: Allocate Spine (Array of pointers)
    int **matrix = (int **)malloc(rows * sizeof(int *));

    // Step 2: Allocate Ribs (Actual rows)
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    // Access: matrix[row][col]
    matrix[1][2] = 99;

    // Step 3: Free (Inside-Out)
    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]);
    }
    free(matrix); // Free spine last
}

// 8. CONST POINTERS RULES
void const_rules()
{
    int x = 10;

    const int *p1 = &x; // Value is const (*p1 = 20 is ILLEGAL). Pointer is modifiable.
    int *const p2 = &x; // Pointer is const (p2 = &y is ILLEGAL). Value is modifiable.
}
