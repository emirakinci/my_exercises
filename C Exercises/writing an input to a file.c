#include <stdio.h>
//Written by @emirakinci. Before using this code check the 'LICENCE' for details.
int main() {

    FILE *doc;
    int N, i;
    char user[20];
    doc = fopen("info.txt", "w");
    if(doc == NULL)
    {
        fprintf(stderr, "FILE NOT FOUND");
    }
    else
    {
        printf("Which sentence do you want to write on file?\n");
        gets(user);
        printf("How many times?\n");
        scanf("%d", &N);

        for(i = 0; i < N; i++)
        {
            fprintf(doc, "%s\n", user);
        }
        printf("Process ended successfully");
    }
    fclose(doc);
    return 0;
}
