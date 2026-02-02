#include <stdio.h>
#include <stdlib.h>

int main()
{
    // YOUR MISSION:
    // 1. Ask the user for a Product Name and a Price (scanf).
    // 2. Open "products.txt" but in append mode ("a").
    // 3. Write usage fprintf() to add the new item to the file on a new line.
    // 4. Close the file.

    char name[50];
    float price;

    printf("Enter new product name: ");
    scanf("%s", name);
    printf("Enter price: ");
    scanf("%f", &price);

    FILE *products;
    products = fopen("products.txt", "a");
    if (products == NULL)
    {
        return 1;
    }
    fprintf(products, "%s %.2f\n", name, price);
    fclose(products);

    return 0;
}
