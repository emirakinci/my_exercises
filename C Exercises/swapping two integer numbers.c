#include <stdio.h>
//Written by @emirakinci. Before using this code check the 'LICENCE' for details.
//This programme aims swapping two integer numbers.
int main() {
    int number1, number2;
    int temporary_number;

    fprintf(stdout, "Enter the numbers:\n");
    scanf("%d%d", &number1, &number2);
    printf("BEFORE:\nnumber1: %d\tnumber2: %d\n", number1, number2);

    temporary_number = number1;
    number1 = number2;
    number2 = temporary_number;

    printf("AFTER:\nnumber1: %d\tnumber2: %d", number1, number2);

    return 0;
}
