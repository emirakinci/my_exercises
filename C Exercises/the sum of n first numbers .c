#include <stdio.h>
//Written by @emirakinci. Before using this code check the 'LICENCE' for details.
//This programme aims computing the sum of first n integer numbers.
int main() {
    int boundary, i, sum = 0;
    printf("Type the boundary:\n");
    scanf("%d", &boundary);

    for(i = 1; i <= boundary; i++)
    {
        if(i == boundary)
        {
            printf("%d = ", i);
        } else{
            printf("%d + ", i);
        }
    }

    for(i = 0; i<=boundary; i++)
    {
        sum = sum + i;
    }
    printf("%d", sum);
    return 0;
}
