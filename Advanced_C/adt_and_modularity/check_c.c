#include "mylib.h"

void check_c(char **m, int n, Data *my_data)
{
    int i, j, k, max = (*my_data).rep, counter = 0;
    char c;

    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            c = m[j][i];
            k=j+1;
            while(k<n)
            {
                if(m[k][i] == c)
                {
                    counter++;
                }
                k++;
            }
            counter++;
            if(counter > max)
            {
                max = counter;

                (*my_data).r = j;
                (*my_data).c = i;
                (*my_data).rep = counter;
            }
            counter = 0;
        }
    }
}