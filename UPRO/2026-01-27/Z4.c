#include <stdio.h>
#include <stdlib.h>

struct Item
{
    char name[50];
    float price;
};

int main()
{
    // TASK 4: The Time Traveler (fseek / ftell)

    // We will use the "savegame.bin" you created in Task 3.
    // It contains: [Sword] [Shield] [Potion]

    FILE *fp = fopen("savegame.bin", "rb");
    if (fp == NULL)
        return 1;

    struct Item item;

    // MISSION 1: Jump to the 2nd item (Shield)
    // Concept: fseek(file_pointer, offset, origin)
    // Origin can be: SEEK_SET (start), SEEK_CUR (current), SEEK_END (end)

    // TODO: Use fseek to skip the first item (sizeof(struct Item)) from SEEK_SET.
    // TODO: Read one item using fread.
    // TODO: Print it (Should be Shield).

    printf("--- Specific Item Read ---\n");
    fseek(fp, sizeof(struct Item), SEEK_SET);
    fread(&item, sizeof(struct Item), 1, fp);
    printf("%s, %.2f", item.name, item.price);

    // MISSION 2: Calculate File Size
    // Concept: Jump to the end, ask "where am I?", jump back.

    // TODO: fseek to SEEK_END.
    // TODO: use ftell(fp) to get current byte position.

    printf("\n--- File Stats ---\n");
    // printf("File size: %ld bytes\n", size);

    long int size;
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    printf("%ld bytes\n", size);

    fclose(fp);
    return 0;
}
