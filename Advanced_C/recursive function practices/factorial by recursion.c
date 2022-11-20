#include <stdio.h>
// Recursive functions practice!!

int factorialCalculate(int number);
int main() {

    int numero;

    printf("enter a number please:\n");
    scanf("%d", &numero);

    printf("%d! = %d", numero, factorialCalculate(numero));
    return 0;
}
int factorialCalculate(int number)
{
   if(number == 1)
   {
       return 1;
   }
    return number * factorialCalculate(number - 1);
}