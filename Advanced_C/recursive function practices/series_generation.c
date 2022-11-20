#include <stdio.h>
#include <stdlib.h>
//programmed by @emirakinci

void series_generation(int start, int end, int increment);
int main() {

    int s, e, i;

    printf("starting & ending values & increment:\n");
    scanf("%d%d%d", &s, &e, &i);


    series_generation(s, e, i);
    return 0;
}

void series_generation(int start, int end, int increment)
{
    if(start > end)
    {
        exit(0);
    }
    printf("%d\t", start);
    series_generation(start + increment, end, increment);
}

