#include <stdio.h>
// Recursive functions practice!!

int multiplication(int number1, int number2)
{
    if(number2 == 0)
    {
        return 0;
    }

    return number1 + multiplication(number1, number2-1);
}
int main() {

    int numero, numero1;

    printf("enter the numbers please:\n");
    scanf("%d%d", &numero, &numero1);

    printf("total: %d", multiplication(numero, numero1));
    return 0;
}
