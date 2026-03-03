#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 1. STRING INPUT (SAFE WITH SPACES)
void safe_string_input()
{
    char str[100];
    printf("Enter string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline if present
    str[strcspn(str, "\n")] = '\0';

    printf("You entered: %s\n", str);
}
/*
Enter string: Hello World
You entered: Hello World
*/

// 2. STRING COMPARISON (CASE SENSITIVE)
void string_comparison()
{
    char str1[50], str2[50];

    if (strcmp(str1, str2) == 0)
    {
        printf("Strings are equal\n");
    }
    else if (strcmp(str1, str2) < 0)
    {
        printf("str1 comes before str2\n");
    }
    else
    {
        printf("str1 comes after str2\n");
    }
}
/*
strcmp("apple", "banana") returns: -1
strcmp("zebra", "apple") returns: 1
strcmp("hello", "hello") returns: 0
*/

// 3. STRING COMPARISON (CASE INSENSITIVE)
int strcasecmp_manual(const char *s1, const char *s2)
{
    while (*s1 && *s2)
    {
        char c1 = tolower(*s1);
        char c2 = tolower(*s2);
        if (c1 != c2)
            return c1 - c2;
        s1++;
        s2++;
    }
    return tolower(*s1) - tolower(*s2);
}
/*
strcasecmp_manual("Hello", "HELLO") returns: 0
strcasecmp_manual("Apple", "banana") returns: -1
*/

// 4. REMOVE SPACES FROM STRING
void remove_spaces(char *str)
{
    char *src = str, *dst = str;
    while (*src)
    {
        if (*src != ' ')
        {
            *dst++ = *src;
        }
        src++;
    }
    *dst = '\0';
}
/*
Before: "Hello World Test"
After:  "HelloWorldTest"
*/

// 5. STRING COPY AND CONCATENATION
void string_copy_concat()
{
    char src[50] = "Hello";
    char dest[100];
    char append[50] = " World";

    strcpy(dest, src);    // Copy: dest = "Hello"
    strcat(dest, append); // Concat: dest = "Hello World"

    // Manual copy
    char manual[100];
    int i;
    for (i = 0; src[i] != '\0'; i++)
    {
        manual[i] = src[i];
    }
    manual[i] = '\0';
}
/*
src: "Hello"
dest after strcpy: "Hello"
dest after strcat: "Hello World"
manual: "Hello"
*/

// 6. FIND CHARACTER/SUBSTRING
void string_search()
{
    char str[] = "Hello World";
    char *pos;

    // Find first occurrence of character
    pos = strchr(str, 'o');
    if (pos)
        printf("Found 'o' at position: %ld\n", pos - str);

    // Find substring
    pos = strstr(str, "World");
    if (pos)
        printf("Found 'World' at position: %ld\n", pos - str);
}
/*
Found 'o' at position: 4
Found 'World' at position: 6
*/

// 7. STRING LENGTH AND CHARACTER PROCESSING
void string_processing()
{
    char str[] = "Hello123";

    printf("Length: %lu\n", strlen(str));

    // Process each character
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isalpha(str[i]))
            printf("%c is letter\n", str[i]);
        if (isdigit(str[i]))
            printf("%c is digit\n", str[i]);
        if (isspace(str[i]))
            printf("Space found\n");
    }
}
/*
Length: 8
H is letter
e is letter
l is letter
l is letter
o is letter
1 is digit
2 is digit
3 is digit
*/

// 8. COMPARE STRINGS IGNORING SPACES AND CASE
int compare_ignore_spaces_case(const char *s1, const char *s2, int *pos1, int *pos2)
{
    int i1 = 0, i2 = 0;

    while (s1[i1] && s2[i2])
    {
        // Skip spaces in s1
        while (s1[i1] == ' ')
            i1++;
        // Skip spaces in s2
        while (s2[i2] == ' ')
            i2++;

        // Check if we reached end
        if (!s1[i1] && !s2[i2])
            break;
        if (!s1[i1] || !s2[i2])
            break;

        // Compare characters (case insensitive)
        char c1 = tolower(s1[i1]);
        char c2 = tolower(s2[i2]);

        if (c1 != c2)
        {
            *pos1 = i1;
            *pos2 = i2;
            return c1 - c2;
        }

        i1++;
        i2++;
    }

    // Skip trailing spaces
    while (s1[i1] == ' ')
        i1++;
    while (s2[i2] == ' ')
        i2++;

    *pos1 = i1;
    *pos2 = i2;
    return (s1[i1] ? 1 : 0) - (s2[i2] ? 1 : 0);
}
/*
compare_ignore_spaces_case("Hello World", "hello  WORLD", &pos1, &pos2)
Returns: 0
pos1: 11, pos2: 12
*/

// 9. STRING TO STRUCT ASSIGNMENT
struct person
{
    char name[50];
    int age;
};

void string_to_struct()
{
    struct person p;
    char input_name[50];

    printf("Enter name: ");
    fgets(input_name, sizeof(input_name), stdin);
    input_name[strcspn(input_name, "\n")] = '\0'; // Remove newline

    strcpy(p.name, input_name); // Use strcpy, NOT assignment!
    p.age = 25;
}
/*
Enter name: John Doe
p.name: "John Doe"
p.age: 25
*/

// 10. REMOVE NEWLINES FROM STRING
void remove_newlines()
{
    char str[100];

    // Method 1: Using strcspn (most common)
    str[strcspn(str, "\n")] = '\0';

    // Method 2: Manual search and replace
    for (int i = 0; str[i]; i++)
    {
        if (str[i] == '\n')
        {
            str[i] = '\0';
            break;
        }
    }

    // Method 3: Remove ALL newlines (not just first)
    int j = 0;
    for (int i = 0; str[i]; i++)
    {
        if (str[i] != '\n')
        {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}
/*
Input: "Hello\nWorld\n"
Method 1 result: "Hello"
Method 2 result: "Hello"
Method 3 result: "HelloWorld"
*/

int main()
{
    return 0;
}