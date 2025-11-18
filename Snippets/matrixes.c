#include <stdio.h>

// Test matrix for examples (3x3)
int test_matrix[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}};

// 1. PRINT MATRIX (FORMATTED MONOSPACE)
void print_matrix(int matrix[][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%4d ", matrix[i][j]); // 4-space padding for up to 9999
        }
        printf("\n");
    }
    printf("\n");
}
/*
   1    2    3
   4    5    6
   7    8    9

Works with larger numbers:
 123  456  789
1000 2000 3000
*/

// 2. ROTATE MATRIX RIGHT (90° CLOCKWISE)
void rotate_right(int src[][3], int dest[][3], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dest[j][n - 1 - i] = src[i][j];
        }
    }
}
/*
Original:        After Right Rotation:
  1   2   3        7   4   1
  4   5   6   →    8   5   2
  7   8   9        9   6   3
*/

// 3. ROTATE MATRIX LEFT (90° COUNTER-CLOCKWISE)
void rotate_left(int src[][3], int dest[][3], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dest[n - 1 - j][i] = src[i][j];
        }
    }
}
/*
Original:        After Left Rotation:
  1   2   3        3   6   9
  4   5   6   →    2   5   8
  7   8   9        1   4   7
*/

// 4. MATRIX ADDITION
void matrix_add(int a[][3], int b[][3], int result[][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}
/*
Matrix A:        Matrix B:        Result A + B:
  1   2   3   +    1   1   1   =    2   3   4
  4   5   6        2   2   2        6   7   8
  7   8   9        3   3   3       10  11  12
*/

// 5. MATRIX SUBTRACTION
void matrix_subtract(int a[][3], int b[][3], int result[][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}
/*
Matrix A:        Matrix B:        Result A - B:
  1   2   3   -    1   1   1   =    0   1   2
  4   5   6        2   2   2        2   3   4
  7   8   9        3   3   3        4   5   6
*/

// 6. MATRIX MULTIPLICATION
void matrix_multiply(int a[][3], int b[][3], int result[][3], int rows, int cols, int common)
{
    // Initialize result matrix to 0
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = 0;
        }
    }

    // Perform multiplication
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            for (int k = 0; k < common; k++)
            {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}
/*
Matrix A:        Matrix B:        Result A × B:
  1   2   3   ×    1   0   0   =   14  12  15
  4   5   6        2   3   2       32  27  33
  7   8   9        3   4   5       50  42  51
*/

// 7. TRANSPOSE MATRIX
void transpose(int src[][3], int dest[][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            dest[j][i] = src[i][j];
        }
    }
}
/*
Original:        Transposed:
  1   2   3        1   4   7
  4   5   6   →    2   5   8
  7   8   9        3   6   9
*/

// 8. SCALAR MULTIPLICATION
void scalar_multiply(int matrix[][3], int scalar, int result[][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrix[i][j] * scalar;
        }
    }
}
/*
Original × 2:
  1   2   3        2   4   6
  4   5   6   →    8  10  12
  7   8   9       14  16  18
*/

// 9. FIND MAX/MIN IN MATRIX
int find_max(int matrix[][3], int rows, int cols)
{
    int max = matrix[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] > max)
            {
                max = matrix[i][j];
            }
        }
    }
    return max;
}

int find_min(int matrix[][3], int rows, int cols)
{
    int min = matrix[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] < min)
            {
                min = matrix[i][j];
            }
        }
    }
    return min;
}
/*
find_max(test_matrix, 3, 3) returns: 9
find_min(test_matrix, 3, 3) returns: 1
*/

// 10. MATRIX DIAGONAL OPERATIONS
int sum_main_diagonal(int matrix[][3], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += matrix[i][i];
    }
    return sum;
}

int sum_anti_diagonal(int matrix[][3], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += matrix[i][n - 1 - i];
    }
    return sum;
}
/*
Main diagonal (1,5,9): sum = 15
Anti diagonal (3,5,7): sum = 15
*/

// 11. CHECK MATRIX PROPERTIES
int is_symmetric(int matrix[][3], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] != matrix[j][i])
            {
                return 0; // Not symmetric
            }
        }
    }
    return 1; // Symmetric
}

int is_identity(int matrix[][3], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j && matrix[i][j] != 1)
                return 0;
            if (i != j && matrix[i][j] != 0)
                return 0;
        }
    }
    return 1;
}
/*
is_symmetric(test_matrix, 3) returns: 0
is_identity(identity_matrix, 3) returns: 1
*/

// 12. COPY MATRIX
void copy_matrix(int src[][3], int dest[][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            dest[i][j] = src[i][j];
        }
    }
}

// 13. ZERO MATRIX
void zero_matrix(int matrix[][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

// 14. IDENTITY MATRIX
void identity_matrix(int matrix[][3], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = (i == j) ? 1 : 0;
        }
    }
}
/*
Identity Matrix:
  1   0   0
  0   1   0
  0   0   1
*/

// 15. MATRIX DEMO FUNCTION
void matrix_demo()
{
    int matrix_a[3][3], matrix_b[3][3], result[3][3];

    // Copy test matrix
    copy_matrix(test_matrix, matrix_a, 3, 3);

    // Create matrix B (all 2s for demo)
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix_b[i][j] = 2;
        }
    }

    printf("Original Matrix A:\n");
    print_matrix(matrix_a, 3, 3);

    printf("Matrix B (all 2s):\n");
    print_matrix(matrix_b, 3, 3);

    printf("A + B:\n");
    matrix_add(matrix_a, matrix_b, result, 3, 3);
    print_matrix(result, 3, 3);

    printf("A × 3 (scalar):\n");
    scalar_multiply(matrix_a, 3, result, 3, 3);
    print_matrix(result, 3, 3);

    printf("A rotated right:\n");
    rotate_right(matrix_a, result, 3);
    print_matrix(result, 3, 3);

    printf("A rotated left:\n");
    rotate_left(matrix_a, result, 3);
    print_matrix(result, 3, 3);

    printf("A transposed:\n");
    transpose(matrix_a, result, 3, 3);
    print_matrix(result, 3, 3);

    printf("Max element: %d\n", find_max(matrix_a, 3, 3));
    printf("Min element: %d\n", find_min(matrix_a, 3, 3));
    printf("Main diagonal sum: %d\n", sum_main_diagonal(matrix_a, 3));
}

int main()
{
    printf("=== MATRIX OPERATIONS DEMO ===\n\n");
    matrix_demo();

    return 0;
}
