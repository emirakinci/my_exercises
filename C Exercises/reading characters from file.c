#include <stdio.h>
//Written by @emirakinci. Before using this code check the 'LICENCE' for details.
int main() {

    FILE *doc;
    char read;
    doc = fopen("info.txt", "r");
    if(doc != NULL)
    {
        while(!feof(doc))
        {
            read = fgetc(doc);
            if(read!=EOF)
            {
                putchar(read);
            }
        }
        printf("Process completed successfully");
    }
    else
    {
        fprintf(stderr, "FILE NOT FOUND");
    }
    fclose(doc);
    return 0;
}
