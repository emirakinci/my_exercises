#include <stdio.h>
#include <stdlib.h>

int *memory_alloc(int *p, int n);
int main() {
    int *my_numbers = NULL;
    int z;

    printf("how many numbers do you want to add?\n");
    scanf("%d", &z);

    if(memory_alloc(my_numbers, z) != NULL)
    {
        printf("Memory has been successfully allocated :)");
    }
    return 0;
}
int *memory_alloc(int *p, int n)
{
    p = (int *) malloc(n* sizeof(int ));
    if(p == NULL)
    {
        fprintf(stderr, "Memory allocation error!");
        exit(EXIT_FAILURE);
    }
    return p;
}
