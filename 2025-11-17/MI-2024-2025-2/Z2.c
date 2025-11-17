#include <stdio.h>
#include <string.h>

struct osoba
{
    char name[20];
    short int birth;
    short int death;
};

int main()
{
    struct osoba osobe[20] =
        {
            {"ElizabetaI", 1533, 1603},
            {"Mozart", 1756, 1791},
            {"Nixon", 1913, 1994},
            {"Lenjin", 1870, 1924},
            {"Kant", 1724, 1804},
            {"Newton", 1643, 1727},
            {"Bismarck", 1815, 1898},
            {"Napoleon", 1769, 1821},
            {"MargaretAnnNeve", 1792, 1903},
            {"EmmaMorano", 1899, 2017},
            {"LujXIV.", 1638, 1715}};
    int n = 12;
    char tempstr[20];
    short birth;
    short death;

    while (n <= 20)
    {
        printf("Osoba %d:\n", n);
        printf("Ime i prezime: "); // the lion does not concern itself with edgar complaining about newlines
        scanf("%s", tempstr);
        if (strcmp(tempstr, ".") == 0)
        {
            break;
        }
        printf("Rodenje: ");
        scanf("%hd", &birth);
        printf("Smrt: ");
        scanf("%hd", &death);
        strcpy(osobe[n - 1].name, tempstr);
        osobe[n - 1].birth = birth;
        osobe[n - 1].death = death;
        n += 1;
    }
    int checkyr;
    int verif;
    printf("Godina za provjeru: \n");
    scanf("%d", &checkyr);
    printf("Suvremenici:\n");
    for (int i = 0; i < n; i++)
    {
        if (osobe[i].birth <= checkyr && osobe[i].death >= checkyr)
        {
            printf("%s (%hd - %hd)\n", osobe[i].name, osobe[i].birth, osobe[i].death);
            verif = 1;
        }
    }
    if (!(verif == 1))
    {
        printf("Nema suvremenika.\n");
    }
}