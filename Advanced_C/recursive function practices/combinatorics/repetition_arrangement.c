#include <stdio.h>
#include <stdlib.h>
int rep_arr(char *val, char *sol, int n, int k, int count, int pos);
int main(void){
    char *val, *sol;
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
    sol = malloc(K*sizeof(char));

    // Insert the values inside the val
    for(int i=0; i<N ;i++)
    {
        val[i] = 'A' + i;
    }

    result = rep_arr(val, sol, N, K, count, pos);
    printf("%d possible outcomes", result);
    return 0;
}
int rep_arr(char *val, char *sol, int n, int k, int count, int pos)
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

    // different from the simple arrangement, here we can re-take the same values inside the array 
    // so, we don't use mark arrray
    for(i=0; i<n; i++)
    {
        sol[pos] = val[i];
        count = rep_arr(val, sol, n, k, count, pos+1);
    }

    return count;
}