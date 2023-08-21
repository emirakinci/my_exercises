#include <stdio.h>
#include <stdlib.h>
#define N 20

int count_c(char *x);
int main() {
    char *p = (char *) malloc(N* sizeof(char ));

    if(p == NULL)
    {
        fprintf(stderr, "Memory allocation error!");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("type the name:\n");
        gets(p);

        printf("there are %d chars", count_c(p));
    }
    return 0;
}
int count_c(char *x)
{
    int i, spaces = 0;

    for(i = 0; *(x+i)!='\0';i++)
    {
        if(*(x+i) == ' ')
        {
            spaces++;
        }
    }

    return i-spaces;
}