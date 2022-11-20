#include <stdio.h>

int powers2(int number);
int main() {
    int N, i;
    printf("how many numbers do you want to generate:\n");
    scanf("%d", &N);

    for(i = 0; i < N; i++)
    {
        printf("2^%d = %d\n", i, powers2(i));
    }
    return 0;
}
int powers2(int number)
{
    if(number == 0)
    {
        return 1;
    }
    return(2 * powers2(number - 1));
}