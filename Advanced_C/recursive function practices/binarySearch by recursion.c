#include <stdio.h>
// Recursive functions practice!!

int binarySearch(int v[], int l, int r, int k);
int main() {

    int array[] = {1, 2, 3, 4, 5}, index;

    index = binarySearch(array, 0, 4, 3);

    if(index == -1)
    {
        fprintf(stderr, "not found in the list");
    }
    else
    {
        printf("found at index %d", index);
    }

    return 0;
}
int binarySearch(int v[], int l, int r, int k)
{
    int c;

    if(l > r)
    {
        return -1;
    }

    c = (l+r)/2;

    if(k < v[c])
    {
        return (binarySearch(v, l, c-1, k));
    }
    if(k > v[c])
    {
        return (binarySearch(v, c+1, r, k));
    }

    return c;
}