#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define NUM_WORDS 100
#define NUM_CHAR2 20
#define NUM_CHAR1 100

typedef struct words{
    char the_word[NUM_CHAR2+1];
    int occurance;
}Words;

int comparison(char *str1, char *str2);
int readWords(Words file_read[], char *fileName);
void readFile(char *file2Name, Words my_words[], int numWords);
int main(void){
    Words the_words[NUM_WORDS];
    int N = readWords(the_words, "e01inB.txt");
    readFile("e01inA.txt", the_words, N);

    for(int i=0; i < N; i++)
    {
        fprintf(stdout, "%s - %d occurrence(s)\n", the_words[i].the_word, the_words[i].occurance);
    }
    return 0;
}
int readWords(Words file_read[], char *fileName)
{
    FILE *doc = fopen(fileName, "r");
    int index = 0;

    if(doc == NULL)
    {
        fprintf(stderr, "File not found!!");
        exit(EXIT_FAILURE);
    }
    while(!feof(doc))
    {
        fscanf(doc, "%s", file_read[index].the_word);
        index++;
    }
    fclose(doc);

    return index;
}
void readFile(char *file2Name, Words my_words[], int numWords)
{
    FILE *doc2 = fopen(file2Name, "r");
    char wordF[NUM_CHAR1];

    if(doc2 == NULL)
    {
        fprintf(stderr, "File not found!!");
        exit(EXIT_FAILURE);
    }
    while(fscanf(doc2, "%s", wordF) == 1)
    {
        for(int j=0; j < numWords; j++)
        {
            if(comparison(wordF, my_words[j].the_word) == 1)
            {
                my_words[j].occurance++;
            }
        }
    }
    fclose(doc2);
}
int comparison(char *str1, char *str2)
{
    if(strlen(str1) != strlen(str2))
    {
        return 0;
    }
    for(int i=0; i < strlen(str1); i++)
    {
        if(tolower(str1[i]) != tolower(str2[i]))
        {
            return 0;
        }
    }
    return 1;
}