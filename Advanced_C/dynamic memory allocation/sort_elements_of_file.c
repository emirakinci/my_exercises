#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100+1
#define nameOfFile "lab2.txt"
#define nameOfOutput "lab2_output.txt"


struct string {
    char *str;
};

struct string *readFile(char *fileName);
void sortElements(struct string *s2, int row);
void insertOutput(char *fileName, struct string *ss, int row);
void dealloc(struct string *ss1, int row)
{
    int i;
    for(i = 0; i < row; i++)
    {
        free(ss1[i].str);
    }
    free(ss1);
}
int main() {
    struct string *s1;
    int R;
    FILE *d;
    d = fopen(nameOfFile, "r");
    fscanf(d, "%d", &R);

    s1 = readFile(nameOfFile);
    sortElements(s1, R);
    insertOutput(nameOfOutput, s1, R);
    dealloc(s1, R);
    return 0;
}
struct string *readFile(char *fileName)
{
    int i, n;
    struct string *s;
    FILE *doc;
    doc = fopen(fileName, "r");
    if(doc == NULL)
    {
        fprintf(stderr, "file not found!");
        exit(EXIT_FAILURE);
    }

    fscanf(doc, "%d", &n);
    fflush(doc);

    s = (struct string *) malloc(n* sizeof(struct string)); // allocating the struct
    if(s == NULL)
    {
        fprintf(stderr, "Memory allocation error!");
        exit(EXIT_FAILURE);
    }

    // allocating the elements of each struct
    for(i = 0; i < n ;i++)
    {
        s[i].str = (char *) malloc(N * sizeof(char ));
        if(s[i].str == NULL)
        {
            fprintf(stderr, "Memory allocation error!");
            exit(EXIT_FAILURE);
        }
    }
    // insert elements to the struct
    for(i = 0; i < n; i++)
    {
        fscanf(doc, "%s", s[i].str);
    }
    fclose(doc);
    return s;
}
void sortElements(struct string *s2, int row)
{
    int i, j;
    char *ptr;

    for (i=1; i<row; i++) {
        ptr = s2[i].str;
        j = i;
        while (--j>=0 && strcmp(ptr, s2[j].str)<0) {
            s2[j+1].str = s2[j].str;
        }
        s2[j+1].str = ptr;
    }
}
void insertOutput(char *fileName, struct string *ss, int row)
{
    int i;
    FILE *d1;
    d1 = fopen(fileName, "w");

    if(d1 == NULL)
    {
        fprintf(stderr, "File not found!!");
        exit(EXIT_FAILURE);
    }
    for(i = 0; i < row; i++)
    {
        if(i+1 == row)
        {
            fprintf(d1, "%s", ss[i].str);
        }
        else
        {
            fprintf(d1, "%s\n", ss[i].str);
        }
    }
    fclose(d1);
}
