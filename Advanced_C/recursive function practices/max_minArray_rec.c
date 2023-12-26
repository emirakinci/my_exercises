#include <stdio.h>

void max(int arr[], int l, int r, int *max_var, int *min_var);
int main(void)
{
    int v[] ={5, 2, 7, 1};
    int max_var = v[0], min_var = v[0];
    max(v, 0, 3, &max_var, &min_var);
    printf("\nmax: %d\nmin: %d", max_var, min_var);
    return 0;
}
void max(int arr[], int l, int r, int *max_var, int *min_var){
    
    int c;
    int m1, m2;
    if(l>=r)
    {
        printf("%d ", arr[l]);
        if(arr[l] > *max_var)
        {
            *max_var = arr[l];
        }

        if(arr[l] < *min_var)
        {
            *min_var = arr[l];
        }
        return;
    }
    c = (l+r)/2;
    max(arr, l, c, max_var, min_var);
    max(arr, c+1, r, max_var, min_var);
}