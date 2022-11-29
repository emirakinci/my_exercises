#include <stdio.h>
#include <stdlib.h>
#define J 10

typedef struct{
    char *name;
    char *surname;
    int *point_taken;
    int final_mark;
}comp;

int performance_calculator(comp p[], int num);
int main() {

    int N, i, j, queue;
    int max = 0;
    printf("how many competitors do we have?\n");
    scanf("%d", &N);

    comp competitor[N];//alternative: *competitor = (comp *)malloc(N * sizeof(comp ));

    for(i = 0; i < N; i++)
    {
        competitor[i].name = (char *)malloc(10 * sizeof(char ));
        competitor[i].surname = (char *)malloc(20 * sizeof(char ));
        competitor[i].point_taken = (int *)malloc(J * sizeof(int ));

        if(competitor[i].name == NULL ||  competitor[i].surname == NULL ||  competitor[i].point_taken == NULL)
        {
            fprintf(stderr, "Memory allocation error!!");
        }
        else
        {
            printf("the name:\n");
            scanf("%s", &(*competitor[i].name));//if I use gets I always have an error!!

            printf("the surname:\n");
            scanf("%s", &(*competitor[i].surname));;// assign the value to the address of the value pointed. structure is this.

            for(j = 0; j < J; j++)
            {
                printf("j%d:\n", j + 1);
                scanf("%d", &(competitor[i].point_taken[j]));

            }
            competitor[i].final_mark = performance_calculator(competitor, i);

            if(competitor[i].final_mark > max)
            {
                max = competitor[i].final_mark;
                queue = i;
            }

            printf("%s %s: %d\n", competitor[i].name, competitor[i].surname, competitor[i].final_mark);//since they are string it is ok to print like this.

            free(competitor[i].name);
            free(competitor[i].surname);
            free(competitor[i].point_taken);
        }
    }
    printf("%d. competitor is the champion with %d points", queue + 1, max);
    return 0;
}
int performance_calculator(comp p[], int num)
{
    int max = p[num].point_taken[0], min = p[num].point_taken[0], sum = 0, i;

    for(i = 0; i < J; i++)
    {
        if(p[num].point_taken[i] > max)
        {
            max = p[num].point_taken[i];
        }
        if(p[num].point_taken[i] < min)
        {
            min = p[num].point_taken[i];
        }

        sum += p[num].point_taken[i];
    }

    return((sum - (max + min)) / (J-2));
}