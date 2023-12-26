#include <stdio.h>
#define fileName "input.txt"
#define MAX_CHAR 15
int main(void){
    FILE *doc;
    char lines[MAX_CHAR+1];

    doc = fopen(fileName, "r");

    while((fscanf(doc, "%s", lines))!=EOF)
    {
        printf("%s\n", lines);
    }
    fclose(doc);
    return 0;
}