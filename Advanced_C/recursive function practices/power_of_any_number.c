#include <stdio.h>
//programmed by @emirakinci
int powerF(int base, int power);
int main() {

    int a, b, i;
    printf("please type the base & power:\n");
    scanf("%d%d",&a, &b);

    for(i = 0; i < b; i++)
    {
        printf("%d^%d = %d\n", a, i, powerF(a, i));
    }
    return 0;
}
int powerF(int base, int power)
{
    if(power == 0)
    {
        return 1;
    }
    return (base * powerF(base, power - 1));
}