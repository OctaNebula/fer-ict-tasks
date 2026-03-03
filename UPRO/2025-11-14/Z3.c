// this task is straight up broken

#include <stdio.h>
#include <string.h>

struct legoFigurica
{
    char name[50];
    int parts[5];
};

int main()
{
    struct legoFigurica figurice[] =
        {
            {"FireworkGuy", {14822018, 13562018, 43222017, 52112017, 34222018}},
            {"WrestlingChampion", {93212015, 34122015, 34772012, 22222014, 13452013}},
            {"CactusGirl", {32332018, 93212015, 34772012, 52112017, 34882016}},
            {"Dobby", {98762018, 97652018, 34772018, 32452016, 34212017}},
            {"Cheerleader", {12322010, 14562010, 32462010, 23762010, 98792010}},
            {"Zombie", {56432010, 76482010, 47822010, 78652010, 45322010}},
            {"Forestman", {23652010, 34762009, 64832008, 57532010, 54882009}},
            {"Mariachi/MaracaMan", {23672010, 93212010, 32452016, 54882010, 34672010}}};

    int n = 9;
    char name[50];

    while (name[0] != '-')
    {
        printf("Unos %d. figure:\n", n);
        printf("Naziv: ");

        scanf("%s", name);
        if (name[0] == '-')
        {
            int serial;
            printf("Serijski broj dijela za provjeru: ");
            scanf("%d", &serial);
            printf("Figure koje sadrze dio %d su:", serial);
            int checker = 0;
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (figurice[i].parts[j] == serial)
                    {
                        printf("\n%s", figurice[i].name);
                        checker = 1;
                        break;
                    }
                }
            }
            if (checker == 0)
            {
                printf("\nNema figura!");
            }
        }
        else
        {
            for (int i = 0; i < 8; i++)
            {
                if (strcmp(figurice[i].name, name) == 0)
                {
                    printf("Serijski brojevi:");
                    for (int j = 0; j < 5; j++)
                    {
                        printf(" %d", figurice[i].parts[j]);
                    }
                }
            }
        }
        n += 1;
    }

    return 0;
}