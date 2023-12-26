#include <stdio.h>
#define fileName "input.txt"
#define MAX_CHAR 15
int main(void){
    FILE *doc;
    char lines[MAX_CHAR+1];

    doc = fopen(fileName, "r");
    
    if(doc == NULL)
    {
        fprintf(stderr, "File not found!");
    }
    
    while((fgets(lines, MAX_CHAR, doc)) != NULL)
    {
        printf("%s", lines);
    }
    fclose(doc);
    return 0;
}
