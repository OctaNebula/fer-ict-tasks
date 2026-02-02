#include <stdio.h>
#include <stdlib.h>

struct Item
{
    char name[50];
    float price;
};

int main()
{
    // TASK 3: Binary I/O (The Speed Demon)

    // PART 1: WRITING
    struct Item shop[3] = {
        {"Sword", 150.0},
        {"Shield", 20.5},
        {"Potion", 5.0}};

    // 1. Open "savegame.bin" in "wb" (Write Binary) mode.
    // 2. Use fwrite() to save the ENTIRE array at once.
    //      Syntax: fwrite(pointer_to_data, size_of_one_element, number_of_elements, file_pointer);
    // 3. Close the file.

    FILE *savegame;
    savegame = fopen("savegame.bin", "wb");
    if (savegame == NULL)
    {
        return 1;
    }

    fwrite(shop, sizeof(struct Item), 3, savegame);

    fclose(savegame);

    printf("Game saved to savegame.bin!\n");

    // PART 2: READING (Verification)
    struct Item loaded_shop[3];

    // 1. Open "savegame.bin" in "rb" (Read Binary) mode.
    // 2. Use fread() to load data into 'loaded_shop'.
    //      Syntax: fread(pointer_to_dest, size_of_one_element, number_of_elements, file_pointer);
    // 3. Print the loaded items to prove it worked.

    FILE *savegame2; // I know I can recycle savegame but I felt like making a new variable
    savegame2 = fopen("savegame.bin", "rb");
    if (savegame2 == NULL)
    {
        return 1;
    }
    fread(loaded_shop, sizeof(struct Item), 3, savegame2);
    fclose(savegame2);

    for (int i = 0; i < 3; i++)
    {
        printf("%s, %.2f\n", loaded_shop[i].name, loaded_shop[i].price);
    }

    return 0;
}
