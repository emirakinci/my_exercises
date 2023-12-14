#include <stdio.h>
#include <stdlib.h>

int simple_arr(char *val, char *sol, int *mark, int n, int k, int count, int pos);
int main(void){
    char *val, *sol;
    int *mark;
    int N, K;
    int count = 0, pos = 0;
    int result;

    // I take the inputs
    printf("how many values do you want to insert ?\n");
    scanf("%d", &N);

    printf("how many will you be choosing among them?\n");
    scanf("%d", &K);
    // Allocate the arrays
    val = malloc(N*sizeof(char));
    mark = malloc(N*sizeof(int));
    sol = malloc(K*sizeof(char));

    // Insert the values inside the val
    for(int i=0; i<N ;i++)
    {
        val[i] = 'A' + i;
    }

    result = simple_arr(val, sol, mark, N, K, count, pos);
    printf("%d possible outcomes", result);
    return 0;
}
int simple_arr(char *val, char *sol, int *mark, int n, int k, int count, int pos)
{
    int i;
    if(pos >= k)
    {
        for(i=0; i<k; i++)
        {
            printf("%c ", sol[i]);
        }
        printf("\n");
        return count+1;
    }

    for(i=0; i<n; i++)
    {
        if(mark[i]==0)
        {
            mark[i] = 1; // I mark the chosen one
            sol[pos] = val[i]; // I assign the chosen value inside solution array
            count = simple_arr(val, sol, mark, n, k, count, pos+1);
            mark[i] = 0; // Unmarked to be chosen again later.
        }
    }
    return count;
}