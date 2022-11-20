#include <stdio.h>
//programmed by @emirakinci

int starPrint(int Range);
int main() {
    int number;
    printf("What is the range of the number:\n");
    scanf("%d", &number);

    starPrint(number);
    return 0;
}
int starPrint(int Range)
{
    int i;
    if(Range == 0)
    {
        return 0;
    }
    for(i = 0; i < Range; i++)
    {
        printf("*\t");
    }
    printf("\n");
    return starPrint(Range - 1);
}

/*      version with void:
 *      
 *      #include <stdlib.h>
 *      void starPrint(int Range)
        {
            int i;
            if(Range == 0)
            {
                exit(0);
            }
            for(i = 0; i < Range; i++)
            {
                printf("*\t");
            }
            printf("\n");
            starPrint(Range - 1);
        }        
 * 
 * 
 */