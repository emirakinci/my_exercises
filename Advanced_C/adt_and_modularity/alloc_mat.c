#include "mylib.h"

void alloc_mat(char ***mat)
{
    FILE *doc;
    int i,j;
    int c;

    doc = fopen(input, "r");
    if(doc == NULL)
    {
        fprintf(stderr, "Memoery allocation error!");
        exit(EXIT_FAILURE);
    }

    (*mat) = (char **)calloc(N, sizeof(char *));
    if((*mat) == NULL)
    {
        fprintf(stderr, "Memoery allocation error!");
        exit(EXIT_FAILURE);
    }
    for(i=0; i<N; i++)
    {
        (*mat)[i] = (char *)calloc(N, sizeof(char));
        if((*mat)[i] == NULL)
        {
            fprintf(stderr, "Memory allocation error!");
            exit(EXIT_FAILURE);
        }
    }

    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            c = fgetc(doc);
            (*mat)[i][j] = c;
        }
        fgetc(doc); // read and ignore new line char
    }

    fclose(doc);
}