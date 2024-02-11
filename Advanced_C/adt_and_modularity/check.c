#include "mylib.h"

void check(char **m, int n){
    Data tops;
    int i, j, k, max = 0, counter = 0;
    char c;

    tops.r = tops.rep = 0;

    // column search
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            c = m[i][j];
            k=j+1;
            while(k<n)
            {
                if(m[i][k] == c)
                {
                    counter++;
                }
                k++;
            }
            counter++;
            if(counter > max)
            {
                max = counter;

                tops.r = i;
                tops.c = j;
                tops.rep = counter;
            }
            counter = 0;
        }
    }
    check_c(m, N, &tops);
    print_result(m, N, &tops);
}