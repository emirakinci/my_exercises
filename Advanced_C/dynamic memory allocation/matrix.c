#include <stdio.h>
#include <stdlib.h>

int main() {
    int **my_mat;
    int r, c, i, j;

    printf("how many rows:\n");
    scanf("%d", &r);
    my_mat = (int **) malloc(r* sizeof(int *));

    if(my_mat == NULL)
    {
        fprintf(stderr, "Memory allocation error!");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("number of columns:\n");
        scanf("%d", &c);
        for(i = 0; i < r; i++)
        {
            my_mat[i] = (int *) malloc(c* sizeof(int ));
            if(my_mat[i] == NULL)
            {
                fprintf(stderr, "Memory allocation error!");
                exit(EXIT_FAILURE);
            }
        }

        for(i = 0; i < r; i++)
        {
            for(j = 0; j < c; j++)
            {
                printf("[%d][%d]: \n", i, j);
                scanf("%d", &my_mat[i][j]);
            }
        }

        for(i = 0; i < r; i++)
        {
            for(j = 0; j < c; j++)
            {
                printf("%d", my_mat[i][j]);
            }
        }
        //free phase
        for(i = 0; i<r; i++)
        {
            free(my_mat[i]);
        }
        free(my_mat);
    }
    return 0;
}