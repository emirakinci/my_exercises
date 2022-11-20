#include <stdio.h>
// Recursive functions practice!!

int fibonacci(int number);
int main() {

    int range, i;

    printf("Please enter a range for Fibonacci sequence:\n");
    scanf("%d", &range);

    int array[range];

    for(i = 0; i <= range; i++)
    {
        array[i] = fibonacci(i);
        printf("%d\t", array[i]);
    }

    return 0;
}
int fibonacci(int number)
{

    if(number == 0 || number == 1)
    {
        return number;
    }
    return (fibonacci(number-2) + fibonacci(number-1));
}