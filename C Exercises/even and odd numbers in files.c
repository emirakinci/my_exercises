#include <stdio.h>
//Written by @emirakinci. Before using this code check the 'LICENCE' for details.
int main() {
    FILE *doc, *doc2;
    int N, i;
    int line = 1;
    char e_numbers, o_numbers;
    if((doc = fopen("odd.txt", "w"))!=NULL)
    {
        printf("Type the boundary:\n");
        scanf("%d", &N);

        for(i = 0; i < N;i++)
        {
            if(i % 2 == 0)
            {
                fprintf(doc, "%5d", i);
                if(line == 10)
                {
                    fprintf(doc, "\n");
                }
                line++;
            }
        }
    }
    else
    {
        fprintf(stderr, "'odd.txt' FILE NOT FOUND");
    }
    fclose(doc);

    printf("The odd numbers:\n");
    doc = fopen("odd.txt", "r");

        while(!feof(doc))
        {
            o_numbers = fgetc(doc);
            if(o_numbers != EOF)
            {
                printf("%c", o_numbers);
            }
        }
    fclose(doc);
    line = 1;
    if((doc2 = fopen("even.txt", "w"))!=NULL)
    {
        for(i = 0; i < N;i++)
        {
            if(i % 2 != 0)
            {
                fprintf(doc2, "%5d", i);
                if(line == 10)
                {
                    fprintf(doc2, "\n");
                }
                line++;
            }
        }
    }
    else
    {
        fprintf(stderr, "'even.txt' FILE NOT FOUND");
    }
    fclose(doc2);

    doc2 = fopen("even.txt", "r");
    printf("\nThe even numbers:\n");
    while(!feof(doc2))
    {
        e_numbers = fgetc(doc);
        if(e_numbers != EOF)
        {
            putchar(e_numbers);
        }
    }
    fclose(doc2);
    return 0;
}
