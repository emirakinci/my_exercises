#include <stdio.h>
#include <stdlib.h>

// exercises from prof's book
// allocating the memory for an array and printing inversely

int main() {

    int n, *array, i;

    printf("n:\n");
    scanf("%d", &n);


    array = (int *) malloc(n * sizeof(int));
    if(array == NULL)
    {
        fprintf(stderr, "MEMORY ALLOCATION ERROR!");
        exit(EXIT_FAILURE);
    }
    else
    {
        fprintf(stdout, "MEMORY ALLOCATION SUCCEEDED!\n");
        for(i = 0; i < n; i++)
        {
            printf("v[%d]:\n", i);
            scanf("%d", &array[i]);
        }

        for(i = n-1; i >= 0; i--)
        {
            printf("%d\t", array[i]);
        }
    }
    free(array);
    return 0;
}