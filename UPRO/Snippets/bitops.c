#include <stdio.h>
#include <limits.h>

// 1. SET BIT TO 1 AT INDEX i
#define SET_BIT(num, i) ((num) | (1 << (i)))
/*
SET_BIT(5, 1) = 5 | 2 = 7
Binary: 101 | 010 = 111
*/

// 2. SET BIT TO 0 AT INDEX i
#define CLEAR_BIT(num, i) ((num) & ~(1 << (i)))
/*
CLEAR_BIT(7, 1) = 7 & ~2 = 5
Binary: 111 & 101 = 101
*/

// 3. FLIP BIT AT INDEX i
#define FLIP_BIT(num, i) ((num) ^ (1 << (i)))
/*
FLIP_BIT(5, 1) = 5 ^ 2 = 7
Binary: 101 ^ 010 = 111
*/

// 4. CHECK IF BIT IS SET AT INDEX i
#define IS_BIT_SET(num, i) (((num) >> (i)) & 1)
/*
IS_BIT_SET(5, 0) returns: 1
IS_BIT_SET(5, 1) returns: 0
Binary 5 = 101, bit 0 is 1, bit 1 is 0
*/

// 5. GET RIGHTMOST SET BIT
#define RIGHTMOST_SET_BIT(num) ((num) & -(num))
/*
RIGHTMOST_SET_BIT(12) returns: 4
Binary 12 = 1100, rightmost set bit is at position 2 (value 4)
*/

// 6. CLEAR RIGHTMOST SET BIT
#define CLEAR_RIGHTMOST_SET(num) ((num) & ((num) - 1))
/*
CLEAR_RIGHTMOST_SET(12) returns: 8
Binary: 1100 becomes 1000
*/

// 7. CHECK IF NUMBER IS POWER OF 2
#define IS_POWER_OF_2(num) ((num) > 0 && ((num) & ((num) - 1)) == 0)
/*
IS_POWER_OF_2(8) returns: 1
IS_POWER_OF_2(6) returns: 0
*/

// 8. COUNT SET BITS (POPCOUNT)
int count_set_bits(unsigned int num)
{
    int count = 0;
    while (num)
    {
        count++;
        num &= (num - 1); // Clear rightmost set bit
    }
    return count;
}
/*
count_set_bits(7) returns: 3
Binary 7 = 111 has 3 set bits
*/

// 9. PRINT BINARY REPRESENTATION
void print_binary(unsigned int num)
{
    for (int i = 31; i >= 0; i--)
    {
        printf("%d", IS_BIT_SET(num, i));
        if (i % 4 == 0)
            printf(" "); // Space every 4 bits
    }
    printf("\n");
}
/*
print_binary(5):
0000 0000 0000 0000 0000 0000 0000 0101
*/

// 10. SWAP TWO NUMBERS WITHOUT TEMP VARIABLE
#define SWAP_XOR(a, b) \
    do                 \
    {                  \
        (a) ^= (b);    \
        (b) ^= (a);    \
        (a) ^= (b);    \
    } while (0)
/*
int x = 5, y = 7;
SWAP_XOR(x, y);
Result: x = 7, y = 5
*/

// 11. ISOLATE RIGHTMOST 0 BIT
#define RIGHTMOST_ZERO_BIT(num) (~(num) & ((num) + 1))
/*
RIGHTMOST_ZERO_BIT(5) returns: 2
Binary 5 = 101, rightmost 0 is at position 1 (value 2)
*/

// 12. SET ALL BITS FROM 0 TO i
#define SET_BITS_0_TO_I(i) ((1 << ((i) + 1)) - 1)
/*
SET_BITS_0_TO_I(3) returns: 15
Binary: 1111 (bits 0, 1, 2, 3 all set)
*/

// 13. EXTRACT BITS FROM POSITION i TO j
#define EXTRACT_BITS(num, i, j) (((num) >> (i)) & ((1 << ((j) - (i) + 1)) - 1))
/*
EXTRACT_BITS(0b11010110, 2, 5) returns: 5
Extracts bits 2-5: 0101
*/

// 14. SET MULTIPLE BITS USING MASK
#define SET_BITS_MASK(num, mask) ((num) | (mask))
/*
SET_BITS_MASK(5, 10) = 5 | 10 = 15
Binary: 0101 | 1010 = 1111
*/

// 15. CLEAR MULTIPLE BITS USING MASK
#define CLEAR_BITS_MASK(num, mask) ((num) & ~(mask))
/*
CLEAR_BITS_MASK(15, 10) = 15 & ~10 = 5
Binary: 1111 & 0101 = 0101
*/

// 16. ROTATE LEFT
unsigned int rotate_left(unsigned int num, int shift)
{
    return (num << shift) | (num >> (32 - shift));
}
/*
rotate_left(0x12345678, 4) returns: 0x23456781
*/

// 17. ROTATE RIGHT
unsigned int rotate_right(unsigned int num, int shift)
{
    return (num >> shift) | (num << (32 - shift));
}
/*
rotate_right(0x12345678, 4) returns: 0x81234567
*/

// 18. FIND POSITION OF RIGHTMOST SET BIT
int find_rightmost_set_pos(unsigned int num)
{
    if (num == 0)
        return -1;
    int pos = 0;
    while ((num & 1) == 0)
    {
        num >>= 1;
        pos++;
    }
    return pos;
}
/*
find_rightmost_set_pos(12) returns: 2
Binary 12 = 1100, rightmost set bit is at position 2
*/

// 19. REVERSE BITS
unsigned int reverse_bits(unsigned int num)
{
    unsigned int result = 0;
    for (int i = 0; i < 32; i++)
    {
        result = (result << 1) | (num & 1);
        num >>= 1;
    }
    return result;
}
/*
reverse_bits(0x12345678) returns: 0x1E6A2C48
*/

// 20. CHECK IF BITS ARE ALTERNATING
int has_alternating_bits(unsigned int num)
{
    unsigned int xor_result = num ^ (num >> 1);
    return (xor_result & (xor_result + 1)) == 0;
}
/*
has_alternating_bits(0xAAAA) returns: 1
has_alternating_bits(0x1234) returns: 0
*/

int main()
{
    // Test functions here during exam
    unsigned int test = 42;
    printf("Original: %u\n", test);
    print_binary(test);

    printf("Set bit 0: %u\n", SET_BIT(test, 0));
    printf("Clear bit 1: %u\n", CLEAR_BIT(test, 1));
    printf("Flip bit 2: %u\n", FLIP_BIT(test, 2));
    printf("Is bit 3 set: %d\n", IS_BIT_SET(test, 3));
    printf("Count set bits: %d\n", count_set_bits(test));

    return 0;
}
