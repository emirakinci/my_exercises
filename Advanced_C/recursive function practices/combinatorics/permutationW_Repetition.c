#include <stdio.h>
#include <stdlib.h>

int perm_rep(char *dist_vals, char *sol, int *count, int n, int n_dist, int counter, int pos);
int main(void){

    char *val_dist, *sol;
    int *counter;
    int N = 5;
    int count = 0, pos = 0;

    val_dist = malloc(N*sizeof(char));
    sol = malloc(N*sizeof(char));
    counter = malloc(N*sizeof(int));

    val_dist[0] = 'K';
    counter[0] = 2;

    val_dist[1] = 'Y';
    counter[1] = 2;

    val_dist[2] = 'M';
    counter[2] = 1;

    val_dist[3] = 'S';
    counter[3] = 1;

    val_dist[4] = 'B';
    counter[4] = 1;
    int result = perm_rep(val_dist, sol, counter, 7, N, count, pos);
    printf("%d possibilites", result);
    return 0;
}
int perm_rep(char *dist_vals, char *sol, int *count, int n, int n_dist, int counter, int pos)
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

    for(i=0; i<n_dist; i++)
    {
        if(count[i]>0)
        {
            count[i]--;
            sol[pos] = dist_vals[i];
            counter = perm_rep(dist_vals, sol, count, n, n_dist, counter, pos+1);
            count[i]++;
        }
    }

    return counter;
}