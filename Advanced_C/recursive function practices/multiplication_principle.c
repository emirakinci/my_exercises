#include <stdio.h>
#include <stdlib.h>
#define MAX_CHOICE 3
typedef struct menu{
    int num_choices;
    char *choices;
}Menus;

int mult_princ(Menus *val, char *sol, int n, int count, int pos);
int main(void){
    int i, count = 0, pos = 0, result;
    int temp = 0;
    int n_choice;
    Menus *val;
    char *sol;

    val = malloc(MAX_CHOICE * sizeof(int));
    for(i=0; i < MAX_CHOICE; i++)
    {
        printf("how many choices do I have?\n");
        scanf("%d", &n_choice);
        val[i].num_choices = n_choice;

        val[i].choices = malloc((val[i].num_choices+1)*sizeof(char));
        for(int j=0; j<n_choice; j++)
        {
            val[i].choices[j] = 'A'+temp;
            temp++;
        }
    }
    sol = malloc((MAX_CHOICE+1)*sizeof(char));
    result = mult_princ(val, sol, MAX_CHOICE, count, pos);
    printf("%d possible outcomes", result);
    return 0;
}
int mult_princ(Menus *val, char *sol, int n, int count, int pos)
{
    int j;
    if(pos >= n)
    {
        for(j=0; j<n; j++)
        {
            printf("%c ", sol[j]);
        }
        printf("\n");

        return count+1;
    }

    for(j=0; j<val[pos].num_choices; j++)
    {
        sol[pos] = val[pos].choices[j];
        count = mult_princ(val, sol, n, count, pos+1);
    }

    return count;
}