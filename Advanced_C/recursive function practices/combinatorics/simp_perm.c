#include <stdio.h>
#include <stdlib.h>
#define N 5

int simp_arr(char *vals, char *sol, int *mark, int n, int counter, int pos);
int main(void){
    char *vals, *sol;
    int *mark;
    int result, counter = 0, pos = 0;

    vals = malloc(N*sizeof(char));
    mark = malloc(N*sizeof(int));

    sol = malloc(N*sizeof(char));

    if(vals == NULL || mark == NULL || sol == NULL)
    {
        fprintf(stderr, "Memory allocation error!");
        exit(EXIT_FAILURE);
    }

    for(int i=0; i<N; i++)
    {
        mark[i] = 0;
        vals[i] = 'A'+i;
    }
    fflush(stdout);
    result = simp_arr(vals, sol, mark, N, counter, pos);
    printf("%d possibilities", result);
    return 0;
}
int simp_arr(char *vals, char *sol, int *mark, int n,  int counter, int pos)
{
    int i;
    if(pos >= n)
    {
        for(i=0; i<n; i++)
        {
            printf("%c ", sol[i]);
        }
        printf("\n");

        return counter+1;
    }

    for(i=0; i<n; i++)
    {
        if(mark[i]==0)
        {
            mark[i] = 1;
            sol[pos] = vals[i];
            counter = simp_arr(vals, sol, mark, n, counter, pos+1);
            mark[i] = 0;
        }
    }

    return counter;
}