#include <stdio.h>
#include <stdlib.h>
//programmed by @emirakinci

void askNumber()
{
    int number;
    printf("type a number:\n");
    scanf("%d", &number);

    if(number == 0)
    {
        exit(0);
    }
    askNumber();
}
int main() {

    askNumber();
    return 0;
}

