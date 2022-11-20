#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//programmed by @emirakinci

void sortNumbers(int *array, int length);
int main() {

    int N, i;
    printf("how many numbers do you want to add:\n");
    scanf("%d" ,&N);

    int *numbers = (int *) calloc(N, sizeof(int ));

    if(numbers == NULL)
    {
        fprintf(stderr, "Memory allocation error!!");
    }
    else
    {
        srand(time(0));
        printf("BEFORE:\n");
        for(i = 0; i < N; i++)
        {
            numbers[i] = rand() % 100;
            printf("%d\t", numbers[i]);
        }
        printf("\n");
        sortNumbers(numbers, N-1);

        printf("AFTER:\n");
        for(i = 0; i < N; i++)
        {
            printf("%d\t", numbers[i]);
        }
        free(numbers);
    }
    return 0;
}
void sortNumbers(int *array, int length)
{
    int temp, i;
    if(length != 0)
    {
        for(i = 0; i < length; i++)
        {
            if(array[i]>array[i+1])
            {
                temp = array[i+1];
                array[i+1] = array[i];
                array[i] = temp;
            }
        }
        sortNumbers(array, length - 1);
    }
}