#include "mylib.h"

void print_result(char **m, int n, Data *my_data)
{
    int i, j;
    if((*my_data).r > (*my_data).c)
    {
        i = (*my_data).r;
        j=0;
        while(j<N)
        {
            printf("%c", m[i][j]);
            j++;
        }
    }
    else
    {
        printf("R:%d C:%d REP:%d\n", (*my_data).r, (*my_data).c, (*my_data).rep);
        i = (*my_data).r; //0
        j= (*my_data).c; //3
        while(i<N)
        {
            printf("%c\n", m[i][j]);
            i++;
        }
    }
}