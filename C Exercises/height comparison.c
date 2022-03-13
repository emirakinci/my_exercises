#include <stdio.h>
#include <stdlib.h>
#define num 150
//Written by @emirakinci. Before using this code check the 'LICENCE' for details.
//This programme decides which student has a height closer to the 150 cm.
int main() {
    int student_number;
    int height, min_h, min_n, difference;

    printf("Type the student number:\n");
    scanf("%d", &student_number);

    printf("Type the height of student:\n");
    scanf("%d", &height);

    difference = abs(num-height);
    min_n = student_number;

    while(student_number > 0)
    {
        printf("Type the student number:\n");
        scanf("%d", &student_number);

        printf("Type the height of student:\n");
        scanf("%d", &height);

        if(abs(num-height) < difference)
        {
            difference = abs(num - height);
            min_h = height;
            min_n = student_number;
        }
    }
    fprintf(stdout, "\nThe student with number %d is closer 150 with the height %d\n", min_n, min_h);
    return 0;
}
