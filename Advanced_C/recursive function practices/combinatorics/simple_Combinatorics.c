#include <stdio.h>

int simp_comb(char *vals, char *sol, int n, int k, int start, int counter, int pos);
int main(void)
{
    int n=4, k=3;
    char vals[] = {'A', 'B', 'C', 'D'};
    char sol[k];
    int pos = 0, counter = 0;
    int start = 0;
    int result;

    result = simp_comb(vals, sol, n, k, start, counter, pos);
    printf("%d possibilities", result);
    return 0;
}
int simp_comb(char *vals, char *sol, int n, int k, int start, int counter, int pos)
{
    int i;

    if(pos >= k)
    {
        for(i=0; i<k ;i++)
        {
            printf("%c ", sol[i]);
        }
        printf("\n");

        return counter+1;
    }


    for(i=start; i<n; i++)
    {
        sol[pos] = vals[i];
        counter = simp_comb(vals, sol, n, k, i+1, counter, pos+1);
    }

    return counter;
}