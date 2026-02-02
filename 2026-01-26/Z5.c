#include <stdio.h>
#include <stdlib.h>

struct Item
{
    char *name;
    float price;
};

void cleanup(struct Item *inventory, int lenght)
{
    for (int i = 0; i < lenght; i++)
    {
        free(inventory[i].name);
    }
    free(inventory);
}

int main()
{
    struct Item *inventory;
    int n;
    printf("How many items? > ");
    scanf("%d", &n);
    inventory = malloc(n * sizeof(struct Item));
    if (inventory == NULL)
    {
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Name lenght? > ");
        int len = 0;
        scanf("%d", &len);
        len++;
        inventory[i].name = malloc(len * sizeof(char));
        if (inventory[i].name == NULL)
        {
            cleanup(inventory, i);
            return 1;
        }
        printf("Enter name > ");
        scanf("%s", inventory[i].name);

        printf("Enter price > ");
        float pri;
        scanf("%f", &pri);
        inventory[i].price = pri;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%s ($%.2f)\n", inventory[i].name, inventory[i].price);
    }
    cleanup(inventory, n);
}
