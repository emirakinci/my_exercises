#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define fileName "lab2B.txt"
#define outputFile "lab2B_output.txt"
#define X (20+1)

char **readFile(char *file);
void sortMat(char **mat, int num);
void insertFile(char *targetFile, char**array, int N)
{
    int i;
    FILE *doc2;
    doc2 = fopen(targetFile, "w");

    if(doc2 == NULL)
    {
        fprintf(stderr, "file does not exist!");
        exit(EXIT_FAILURE);
    }

    fprintf(doc2, "%d\n", N);
    for(i = 0; i < N; i++)
    {

        if(i+1 == N)
        {
            fprintf(doc2, "%s", array[i]);
        }
        else
        {
            fprintf(doc2, "%s\n", array[i]);
        }
    }
    fclose(doc2);
}
void deallocate(char **my_array, int N);
int main() {
    FILE *doc1;
    char **my_values;
    int nR, nC;

    doc1 = fopen(fileName, "r");
    if(doc1 == NULL)
    {
        fprintf(stderr, "file '%s' does not exist!", fileName);
        exit(EXIT_FAILURE);
    }
    fscanf(doc1, "%d%d", &nR, &nC);
    fclose(doc1);

    my_values = readFile(fileName);
    sortMat(my_values, nR*nC);
    insertFile(outputFile, my_values, nR*nC);
    deallocate(my_values, nR*nC);
    return 0;
}
char **readFile(char *file)
{
    int R, C, N;
    int i;
    char **values;
    FILE *doc;

    doc = fopen(file, "r");

    if(doc == NULL)
    {
        fprintf(stderr, "file does not exist!");
        exit(EXIT_FAILURE);
    }
    fscanf(doc, "%d%d", &R, &C);

    N = R*C;

    values = (char **) malloc(N * sizeof(char *));
    if(values == NULL)
    {
        fprintf(stderr, "memory can't be allocated!");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < N; i++)
    {
        values[i] = (char *) malloc(X* sizeof(char ));
        if(values[i] == NULL)
        {
            fprintf(stderr, "memory allocation error!!");
            exit(EXIT_FAILURE);
        }
    }

    for(i = 0; i < N ;i++)
    {
        fscanf(doc, "%s", values[i]);
    }

    fclose(doc);
    return values;
}
//here I used insertion sort algorithm!
void sortMat(char **mat, int num)
{
    int i, j;
    char *ptr;

    for(i = 0; i < num; i++)
    {
        ptr = mat[i];
        j = i;

        while(--j>=0 && strcmp(ptr, mat[j])<0)
        {
            mat[j+1] = mat[j];
        }
        mat[j+1] = ptr;
    }
}
void deallocate(char **my_array, int N)
{
    int j;
    for(j = 0; j < N; j++)
    {
        free(my_array[j]);
    }
    free(my_array);

    fprintf(stdout, "Memory successfully deallocated!");
    exit(EXIT_SUCCESS);
}