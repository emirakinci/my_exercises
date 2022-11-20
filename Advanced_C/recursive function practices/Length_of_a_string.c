#include <stdio.h>
#include <stdlib.h>
//programmed by @emirakinci


int lengthOfChar(char *character, int begin);
int main() {

    char *my_sentence = (char *)malloc(10* sizeof(char ));//10 is chosen randomly

    if(my_sentence == NULL)
    {
        fprintf(stderr, "Memory allocation error!");
    }
    else
    {
        printf("tell me your sentence:\n");
        gets(my_sentence);

        printf("the length of your sentence is %d characters:\n", lengthOfChar(my_sentence, 0));
        free(my_sentence);
    }
    return 0;
}
int lengthOfChar(char *character, int begin)
{
    if(character[begin] == '\0')
    {
        return 0;
    }
    return(1 + lengthOfChar(character, begin + 1));
}
