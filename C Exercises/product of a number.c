#include <stdio.h>
//Written by @emirakinci. Before using this code check the 'LICENCE' for details.
//This programme aims printing the product of an integer number until any boundary.
int main() {
    int number, boundary;
    int i = 0;
    int line = 1;
    fprintf(stdout, "Please enter the number and boundary respectively:\n");
    scanf("%d%d", &number, &boundary);

    while(number*i < boundary)
    {
        printf("%5d", number*i);
        //The width of outputs has been chosen arbitrarily.
        if(line == number)
        {
            printf("\n");
            line = 0;
        }
        i++;
        line++;
    }
    return 0;
}
