#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

struct person_s
{
    int code;
    char name[128];
    float salary;
};

bool capitalizeName(struct person_s *person)
{
    bool newWord = true;
    if (strlen(person->name) == 0)
    {
        return false;
    }

    for (int i = 0; i < strlen(person->name); i++)
    {
        char c = person->name[i];
        if (c == ' ' || c == '-')
        {
            newWord = true;
        }
        else
        {
            if (newWord)
            {
                person->name[i] = toupper(c);
                newWord = false;
            }
            else
            {
                person->name[i] = tolower(c);
            }
        }
    }
    return true;
}