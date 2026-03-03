#include <stdio.h>
#include <stdlib.h>

struct Item
{
    int id;
    float val;
};

// 1. OPENING SAFELY
FILE *open_file_safe(const char *filename, const char *mode)
{
    FILE *fp = fopen(filename, mode);
    if (fp == NULL)
    {
        perror("Error opening file"); // Prints OS error message
        return NULL;
    }
    return fp;
}

// 2. READING TEXT (fscanf - Space separated)
void read_text_scans(FILE *fp)
{
    char name[100];
    int age;

    // Returns number of successfully matched items
    // Loop until EOF or mismatch
    while (fscanf(fp, "%s %d", name, &age) == 2)
    {
        printf("Read: %s is %d\n", name, age);
    }
}

// 3. READING LINES (fgets - Whole line including spaces)
void read_text_lines(FILE *fp)
{
    char buffer[256];

    // Reads until newline or buffer full
    // Returns NULL on EOF
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        printf("Line: %s", buffer);
    }
}

// 4. WRITING/APPENDING TEXT
void write_text(FILE *fp)
{
    // "w" clears file, "a" appends
    fprintf(fp, "Log Entry: %d - %.2f\n", 1, 99.99);
}

// 5. BINARY WRITE (Entire Array)
void save_binary(const char *filename, struct Item *arr, int count)
{
    FILE *fp = fopen(filename, "wb"); // 'b' is crucial
    if (!fp)
        return;

    // Write whole block
    fwrite(arr, sizeof(struct Item), count, fp);

    fclose(fp);
}

// 6. BINARY READ (Entire Array)
void load_binary(const char *filename, struct Item *buffer, int max_count)
{
    FILE *fp = fopen(filename, "rb");
    if (!fp)
        return;

    // Returns number of elements read
    int read_count = fread(buffer, sizeof(struct Item), max_count, fp);

    fclose(fp);
}

// 7. FILE SIZE (Seek & Tell)
long get_file_size(FILE *fp)
{
    long current_pos = ftell(fp); // Remember current

    fseek(fp, 0, SEEK_END); // Jump to end
    long size = ftell(fp);  // Read position

    fseek(fp, current_pos, SEEK_SET); // Restore position!
    return size;
}

// 8. RANDOM ACCESS (Jump)
void read_specific_item(FILE *fp, int index)
{
    struct Item it;

    // Jump to the (index)-th item
    fseek(fp, index * sizeof(struct Item), SEEK_SET);

    if (fread(&it, sizeof(struct Item), 1, fp) == 1)
    {
        printf("Item %d: %f\n", it.id, it.val);
    }
}
