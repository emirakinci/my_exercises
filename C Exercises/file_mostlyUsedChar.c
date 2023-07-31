#include <stdio.h>
#include <stdlib.h>
#define N 26
// program finding the mostly used character at a file

char maxChar(FILE *doc1)
{
    int i, repeat_count[N];
    char c, alphabet[N];
    char r;
    int max;

    for(c = 'a', i = 0; c <= 'z'; c++, i++)
    {
        alphabet[i] = c;
        repeat_count[i] = 0;
    }

    while(!feof(doc1))
    {
        r = fgetc(doc1);
        for(i = 0; i < N; i++)
        {
            if(r == alphabet[i])
            {
                repeat_count[i]++;
                break;
            }
        }
    }

    max = 0;
    for(i = 0; i < N; i++)
    {
        if(repeat_count[i] > max)
        {
            max = i;
        }
    }
    return alphabet[max];
}
void readFile(char fileName[]);
int main(void)
{
    readFile("lorem.txt");
    return 0;
}
void readFile(char fileName[])
{
    FILE *doc;
    doc = fopen(fileName, "r");
    char result;
    if(doc !=NULL)
    {
        result = maxChar(doc);
        printf("%c is the mostly used character at the file", result);
    }
    else
    {
        fprintf(stderr, "file not found!!");
        exit(EXIT_FAILURE);
    }
}