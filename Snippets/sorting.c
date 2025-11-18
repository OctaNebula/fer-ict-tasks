#include <stdio.h>
#include <string.h>

// SORTING ALGORITHMS CHEAT SHEET FOR EXAM

// Test array for all examples
int test_array[10] = {7, 2, 9, 1, 5, 6, 3, 8, 4, 10};

// Helper function to print array
void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Helper function to copy array for testing
void copy_array(int dest[], int src[], int size)
{
    for (int i = 0; i < size; i++)
    {
        dest[i] = src[i];
    }
}

// 1. BUBBLE SORT - Most Common for Beginners
void bubble_sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
/*
Before: 7 2 9 1 5 6 3 8 4 10
After:  1 2 3 4 5 6 7 8 9 10
Time: O(n²), Space: O(1)
*/

// 2. SELECTION SORT - Find Min and Swap
void selection_sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_idx = i;

        // Find minimum element in remaining array
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }

        // Swap minimum with first element
        if (min_idx != i)
        {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}
/*
Before: 7 2 9 1 5 6 3 8 4 10
After:  1 2 3 4 5 6 7 8 9 10
Time: O(n²), Space: O(1)
*/

// 3. INSERTION SORT - Insert in Correct Position
void insertion_sort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        // Move elements greater than key one position ahead
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
/*
Before: 7 2 9 1 5 6 3 8 4 10
After:  1 2 3 4 5 6 7 8 9 10
Time: O(n²), Space: O(1)
*/

// 4. MERGE SORT - Divide and Conquer
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge temp arrays back
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
/*
Before: 7 2 9 1 5 6 3 8 4 10
After:  1 2 3 4 5 6 7 8 9 10
Time: O(n log n), Space: O(n)
*/

// 5. QUICK SORT - Partition and Recursion
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // Choose last element as pivot
    int i = low - 1;       // Index of smaller element

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap arr[i+1] and arr[high] (pivot)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}
/*
Before: 7 2 9 1 5 6 3 8 4 10
After:  1 2 3 4 5 6 7 8 9 10
Time: O(n log n) avg, O(n²) worst, Space: O(log n)
*/

// 6. COUNTING SORT - For Small Range Numbers
void counting_sort(int arr[], int size)
{
    // Find max element to determine range
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    // Create counting array
    int count[max + 1];
    for (int i = 0; i <= max; i++)
    {
        count[i] = 0;
    }

    // Count occurrences
    for (int i = 0; i < size; i++)
    {
        count[arr[i]]++;
    }

    // Reconstruct array
    int index = 0;
    for (int i = 0; i <= max; i++)
    {
        while (count[i] > 0)
        {
            arr[index++] = i;
            count[i]--;
        }
    }
}
/*
Before: 7 2 9 1 5 6 3 8 4 10
After:  1 2 3 4 5 6 7 8 9 10
Time: O(n + k), Space: O(k) where k is range
*/

// 7. REVERSE SORT (DESCENDING ORDER)
void bubble_sort_desc(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            { // Change > to < for descending
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
/*
Before: 7 2 9 1 5 6 3 8 4 10
After:  10 9 8 7 6 5 4 3 2 1
*/

// 8. SORTING COMPARISON FUNCTION
void test_all_sorts()
{
    int arr[10];

    printf("Original array: ");
    print_array(test_array, 10);

    // Test Bubble Sort
    copy_array(arr, test_array, 10);
    bubble_sort(arr, 10);
    printf("Bubble Sort:    ");
    print_array(arr, 10);

    // Test Selection Sort
    copy_array(arr, test_array, 10);
    selection_sort(arr, 10);
    printf("Selection Sort: ");
    print_array(arr, 10);

    // Test Insertion Sort
    copy_array(arr, test_array, 10);
    insertion_sort(arr, 10);
    printf("Insertion Sort: ");
    print_array(arr, 10);

    // Test Merge Sort
    copy_array(arr, test_array, 10);
    merge_sort(arr, 0, 9);
    printf("Merge Sort:     ");
    print_array(arr, 10);

    // Test Quick Sort
    copy_array(arr, test_array, 10);
    quick_sort(arr, 0, 9);
    printf("Quick Sort:     ");
    print_array(arr, 10);

    // Test Counting Sort
    copy_array(arr, test_array, 10);
    counting_sort(arr, 10);
    printf("Counting Sort:  ");
    print_array(arr, 10);

    // Test Descending Sort
    copy_array(arr, test_array, 10);
    bubble_sort_desc(arr, 10);
    printf("Descending:     ");
    print_array(arr, 10);
}

// 9. SORTING ALGORITHMS SUMMARY
/*
COMPLEXITY COMPARISON:
┌─────────────────┬─────────────┬─────────────┬─────────────┐
│ Algorithm       │ Best Case   │ Average     │ Worst Case  │
├─────────────────┼─────────────┼─────────────┼─────────────┤
│ Bubble Sort     │ O(n)        │ O(n²)       │ O(n²)       │
│ Selection Sort  │ O(n²)       │ O(n²)       │ O(n²)       │
│ Insertion Sort  │ O(n)        │ O(n²)       │ O(n²)       │
│ Merge Sort      │ O(n log n)  │ O(n log n)  │ O(n log n)  │
│ Quick Sort      │ O(n log n)  │ O(n log n)  │ O(n²)       │
│ Counting Sort   │ O(n + k)    │ O(n + k)    │ O(n + k)    │
└─────────────────┴─────────────┴─────────────┴─────────────┘

WHEN TO USE:
- Bubble/Selection/Insertion: Small arrays, learning purposes
- Merge Sort: Guaranteed O(n log n), stable sort
- Quick Sort: Generally fastest, good average case
- Counting Sort: Small range of integers
*/

int main()
{
    printf("=== SORTING ALGORITHMS DEMO ===\n\n");
    test_all_sorts();

    return 0;
}
