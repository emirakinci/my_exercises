#include <stdio.h>
#define fileName "input.txt"

int main(void){
    FILE *doc;
    char c;
    doc = fopen(fileName, "r");
    
    if(doc == NULL)
    {
        fprintf(stderr, "File not found!");
    }

    while((c=fgetc(doc)) != EOF)
    {
        printf("%c", c);
    }
    fclose(doc);
    return 0;
}