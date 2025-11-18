#include <stdio.h>
#include <string.h>

// STRUCT OPERATIONS CHEAT SHEET FOR EXAM

// 1. BASIC STRUCT DEFINITION
struct student
{
    char name[50];
    int id;
    float grade;
    int courses[5];
    int course_count;
};

// 2. STRUCT INITIALIZATION
void struct_initialization()
{
    // Method 1: Initialize at declaration
    struct student s1 = {"John Doe", 12345, 85.5, {90, 78, 92}, 3};

    // Method 2: Initialize empty then assign
    struct student s2;
    strcpy(s2.name, "Jane Smith"); // Use strcpy for strings!
    s2.id = 67890;
    s2.grade = 92.0;
    s2.courses[0] = 95;
    s2.courses[1] = 88;
    s2.course_count = 2;

    // Method 3: Zero initialization
    struct student s3 = {0}; // Sets all fields to 0
}
/*
s1.name: "John Doe"
s1.id: 12345
s1.grade: 85.500000
s2.name: "Jane Smith"
s2.id: 67890
*/

// 3. ARRAY OF STRUCTS
void struct_array()
{
    struct student class[3] = {
        {"Alice", 111, 88.0, {85, 90, 87}, 3},
        {"Bob", 222, 76.5, {70, 80, 79}, 3},
        {"Carol", 333, 91.2, {95, 88, 93}, 3}};

    // Access array elements
    printf("Student 0: %s\n", class[0].name);
    printf("Student 1 grade: %.1f\n", class[1].grade);
}
/*
Student 0: Alice
Student 1 grade: 76.5
*/

// 4. STRUCT INPUT FROM USER
void struct_input()
{
    struct student s;

    printf("Enter name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0'; // Remove newline

    printf("Enter ID: ");
    scanf("%d", &s.id);

    printf("Enter grade: ");
    scanf("%f", &s.grade);

    printf("How many courses: ");
    scanf("%d", &s.course_count);

    for (int i = 0; i < s.course_count; i++)
    {
        printf("Course %d grade: ", i + 1);
        scanf("%d", &s.courses[i]);
    }
}
/*
Enter name: Mike Johnson
Enter ID: 555
Enter grade: 87.5
How many courses: 2
Course 1 grade: 85
Course 2 grade: 90
*/

// 5. STRUCT COMPARISON AND SEARCH
int find_student_by_id(struct student arr[], int size, int target_id)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i].id == target_id)
        {
            return i; // Return index if found
        }
    }
    return -1; // Not found
}

int find_student_by_name(struct student arr[], int size, const char *target_name)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(arr[i].name, target_name) == 0)
        {
            return i;
        }
    }
    return -1;
}
/*
find_student_by_id(class, 3, 222) returns: 1
find_student_by_name(class, 3, "Carol") returns: 2
find_student_by_id(class, 3, 999) returns: -1
*/

// 6. STRUCT CALCULATIONS
float calculate_average_grade(struct student s)
{
    if (s.course_count == 0)
        return 0.0;

    int sum = 0;
    for (int i = 0; i < s.course_count; i++)
    {
        sum += s.courses[i];
    }
    return (float)sum / s.course_count;
}

struct student find_best_student(struct student arr[], int size)
{
    struct student best = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i].grade > best.grade)
        {
            best = arr[i];
        }
    }
    return best;
}
/*
calculate_average_grade(s1) returns: 86.666664
find_best_student(class, 3).name: "Carol"
find_best_student(class, 3).grade: 91.200000
*/

// 7. STRUCT SORTING
void sort_students_by_grade(struct student arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j].grade < arr[j + 1].grade)
            {
                // Swap entire structs
                struct student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
/*
Before sorting: Alice(88.0), Bob(76.5), Carol(91.2)
After sorting:  Carol(91.2), Alice(88.0), Bob(76.5)
*/

// 8. STRUCT COPYING
void copy_student(struct student *dest, const struct student *src)
{
    strcpy(dest->name, src->name);
    dest->id = src->id;
    dest->grade = src->grade;
    dest->course_count = src->course_count;

    for (int i = 0; i < src->course_count; i++)
    {
        dest->courses[i] = src->courses[i];
    }
}

void struct_assignment()
{
    struct student s1 = {"Original", 123, 85.0, {80, 90}, 2};
    struct student s2;

    // Method 1: Direct assignment (works for structs!)
    s2 = s1;

    // Method 2: Manual copy (when you need control)
    struct student s3;
    copy_student(&s3, &s1);
}
/*
s2.name: "Original"
s2.id: 123
s3.name: "Original"
s3.id: 123
*/

// 9. STRUCT PRINTING
void print_student(const struct student *s)
{
    printf("Name: %s\n", s->name);
    printf("ID: %d\n", s->id);
    printf("Grade: %.1f\n", s->grade);
    printf("Courses (%d): ", s->course_count);
    for (int i = 0; i < s->course_count; i++)
    {
        printf("%d ", s->courses[i]);
    }
    printf("\n");
}
/*
Name: John Doe
ID: 12345
Grade: 85.5
Courses (3): 90 78 92
*/

// 10. STRUCT WITH CONDITIONAL OPERATIONS
void update_grade_if_better(struct student *s, float new_grade)
{
    if (new_grade > s->grade)
    {
        s->grade = new_grade;
        printf("Grade updated to %.1f\n", new_grade);
    }
    else
    {
        printf("Grade not updated (%.1f <= %.1f)\n", new_grade, s->grade);
    }
}

int count_passing_students(struct student arr[], int size, float passing_grade)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i].grade >= passing_grade)
        {
            count++;
        }
    }
    return count;
}
/*
update_grade_if_better(&s1, 90.0):
Grade updated to 90.0

count_passing_students(class, 3, 80.0) returns: 2
*/

int main()
{
    // Test struct operations here during exam
    struct student test = {"Test Student", 999, 75.0, {80, 70, 85}, 3};

    printf("Original student:\n");
    print_student(&test);

    printf("\nAverage course grade: %.1f\n", calculate_average_grade(test));

    update_grade_if_better(&test, 82.0);

    return 0;
}
