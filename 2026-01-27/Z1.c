#include <stdio.h>
#include <stdlib.h>

// We will stick with your Item struct, it's perfect for this.
struct Item
{
    char name[50]; // Static size is easier for file reading beginners
    float price;
};

int main()
{
    // YOUR MISSION:
    // 1. Open "products.txt" for reading ("r").
    // 2. Read all items until the end of the file.
    // 3. Print them to the console.
    // 4. Close the file.

    struct Item currentItem;

    FILE *fp;
    fp = fopen("products.txt", "r");
    if (fp == NULL)
    {
        printf("File not found!");
        return 1;
    }

    while (fscanf(fp, "%s %f", currentItem.name, &currentItem.price) == 2)
    {
        printf("Item: %s, Price: $%.2f\n", currentItem.name, currentItem.price);
    }

    fclose(fp);

    return 0;
}
