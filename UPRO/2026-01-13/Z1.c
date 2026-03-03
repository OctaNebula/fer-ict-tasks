#include <stdio.h>
#include <string.h>

#define MAX_OZNAKA 5
#define MAX_NAZIV 20

struct dionica_s
{
    char oznaka[MAX_OZNAKA];
    float cijena;
    char naziv[MAX_NAZIV];
};

struct portfelj_s
{
    char oznaka[MAX_OZNAKA];
    int kolicina;
};

float IzracunajVrijednostPortfelja(struct dionica_s *dionice, int broj_dionica, struct portfelj_s *moj_portfelj, int broj_dionica_u_mom_portfelju)
{
    float money = 0;
    for (int i = 0; i < broj_dionica_u_mom_portfelju; i++)
    {
        for (int j = 0; j < broj_dionica; j++)
        {
            if (strcmp(moj_portfelj[i].oznaka, dionice[j].oznaka) == 0)
            {
                money += dionice[j].cijena * moj_portfelj[i].kolicina;
            }
        }
    }
    return money;
}
