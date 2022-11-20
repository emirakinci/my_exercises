#include <stdio.h>
// Recursive functions practice!!

int findMax(int v[], int l, int r);
int main() {

    int array[] = {3, 10, 40, 6};

    printf("the max is : %d", findMax(array, 0, 3));

    return 0;
}
int findMax(int v[], int l, int r)
{
    int c, m1, m2;

    if(l >= r)
    {
        return v[l];
    }

    c = (l+r)/2;
    m1 = findMax(v, l, c);
    m2 = findMax(v, c+1, r);

    if(m1 > m2)
    {
        return m1;
    }
    else
    {
        return m2;
    }
}