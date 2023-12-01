#include <stdio.h>
#include <stdlib.h>

int max(int arr[], int l, int r);
int main(void)
{
    int v[] ={3, 10, 6 ,40};
    printf("the largest : %d", max(v, 0, 3));
    return 0;
}
int max(int arr[], int l, int r){

    int c, m1, m2;

    if(l>=r)
    {
        return arr[l];
    }

    c = (l+r)/2;
    m1 = max(arr, l, c);
    m2 = max(arr, c+1, r);

    if(m1 > m2)
    {
        return m1;
    }
    else
    {
        return m2;
    }
}