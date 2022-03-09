#include <stdio.h>
//Written by @emirakinci. Before using this code check the 'LICENCE' for details.
//This programme aims finding maximum and minimum numbers.
int main() {
    float max, min;
    float num1, num2;

    fprintf(stdout, "Please enter the numbers:\n");
    scanf("%f%f", &num1, &num2);

    max = num2;
    min = num1;

    if(num1 == num2)
    {
        printf("These numbers are equal!!\n%.2f = %.2f", num1, num2);
    } else{
        if(num1 > max)
        {
            max = num1;
        }
        if(num2 < min)
        {
            min = num2;
        }
        fprintf(stdout, "MAXIMUM: %.2f\nMINIMUM: %.2f", max, min);
    }
    return 0;
}
