#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//programmed by @emirakinci

void reverseSentence(char *sentence, int l);
int main() {

    char *my_sentence = (char *) malloc(sizeof(char ));
    if(my_sentence == NULL)
    {
        fprintf(stderr, "Memory allocation error!");
    }
    else
    {
        printf("Type your sentence:\n");
        gets(my_sentence);

        reverseSentence(my_sentence, strlen(my_sentence)-1);
    }
    return 0;
}
void reverseSentence(char *sentence, int l)
{
    if(l == 0)
    {
        printf("%c", sentence[l]);
        exit(0);
    }
    printf("%c", sentence[l]);
    reverseSentence(sentence, l-1);
}
