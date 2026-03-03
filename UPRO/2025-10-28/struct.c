#include <stdio.h>

struct Car
{
    char brand[20];
    int year;
    float price;
    int rating;
};

int main()
{
    struct Car myCar = {"Toyota", 2020, 25000.5, 10};
    struct Car myCar2 = {"Honda", 2015, 20000.1, 7};

    printf("Brand: %s\n", myCar.brand);
    printf("Year: %d\n", myCar.year);
    printf("Price: %.2f\n", myCar.price);

    printf("%d", myCar2.year);
    printf("%d", myCar.rating);

    return 0;
}