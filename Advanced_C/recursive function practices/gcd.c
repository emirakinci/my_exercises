#include <stdio.h>

int gcd(int n1, int n2);
int main(void){
    int x , y;
    int result;

    printf("type the numbers respectively:\n");
    scanf("%d%d", &x, &y);
    result = gcd(x, y);
    printf("gcd(%d, %d) is %d", x, y, result);
    return 0;
}
int gcd(int n1, int n2)
{
    if(n1 == n2)
    {
        return n1;
    }

    if(n1>n2)
    {
        return(gcd(n1-n2, n2));
    }
    else
    {
        return(gcd(n1, n2-n1));
    }
}