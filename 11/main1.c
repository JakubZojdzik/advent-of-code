#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 80
#define MONKEYS 8

int itemscnt[10];
int items[10][1000];
char act[10];
int actval[] = {3, -1, 1, 8, 3, 4, 17, 7};
int mod[] = {11, 7, 3, 5, 17, 13, 19, 2};
int yes[] = {2, 0, 7, 6, 1, 6, 4, 5};
int no[] = {7, 2, 5, 4, 0, 3, 1, 3};
int activity[10];

int operation(int inp, int ind)
{
    if(ind == 1) return (inp*inp) / 3;
    if(act[ind] == '+')
    {
        return (inp + actval[ind]) / 3;
    }
    else if(act[ind] == '*')
    {
        return (inp * actval[ind]) / 3;
    }
}

int main(int argc, char **argv)
{
    char line[MAX_LINE_LENGTH] = {0};

    FILE *file = fopen("inp", "r");

    for(int i = 0; i < MONKEYS; i++)
    {
        fgets(line, MAX_LINE_LENGTH, file);
        fgets(line, MAX_LINE_LENGTH, file);
        int pocz = 18;
        int itr = 0;
        for(int j = pocz; line[j] != '\n'; j++)
        {
            if(line[j+1] == ',' || line[j+1] == '\n')
            {
                char subbuff[5];
                memcpy(subbuff, &line[pocz], j-pocz+1);
                subbuff[j-pocz+1] = '\0';
                items[i][itr] = atoi(subbuff);
                pocz = j+3;
                itr++;
            }
        }
        itemscnt[i] = itr;

        fgets(line, MAX_LINE_LENGTH, file);
        act[i] = line[23];
        fgets(line, MAX_LINE_LENGTH, file);
        fgets(line, MAX_LINE_LENGTH, file);
        fgets(line, MAX_LINE_LENGTH, file);
        fgets(line, MAX_LINE_LENGTH, file);
    }
    fclose(file);
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < MONKEYS; j++)
        {
            activity[j] += itemscnt[j];
            for(int k = 0; k < itemscnt[j]; k++)
            {
                int nast = operation(items[j][k], j);
                if(nast % mod[j] == 0)
                {
                    items[yes[j]][itemscnt[yes[j]]] = nast;
                    itemscnt[yes[j]]++;
                }
                else
                {
                    items[no[j]][itemscnt[no[j]]] = nast;
                    itemscnt[no[j]]++;
                }
            }
            itemscnt[j] = 0;
        }
    }
    for(int i = 0; i < MONKEYS; i++)
    {
        printf("activity[%d] = %d\n", i, activity[i]);
    }
}
