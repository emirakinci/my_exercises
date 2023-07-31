#include <stdio.h>
#define MAX 3

int symmetryCheck(int mat[MAX][MAX], int *d)
{
    int i, j;
    *d = 1;

    for(i = 0; i < MAX; i++)
    {
        for(j = 0; j < MAX; j++)
        {
            if(mat[i][j] != mat[j][i])
            {
                *d = 0;
            }
        }
    }
    return *d;
}
int diagonalCheck(int mat[MAX][MAX], int *v);
int main() {

   int matrix[MAX][MAX] = {
           {9, 0, 0},
           {0, 1, 0},
           {0, 0, 1}
   }, r, *value;

   int k, *v2;

   r = symmetryCheck(matrix, &value);
   k = diagonalCheck(matrix, &v2);
   if(r == 1)
   {
       printf("your matrix is symmetric\n");
   }
   else
   {
       fprintf(stderr, "your matrix is not symmetric\n");
   }

   if(k == 1)
   {
       printf("your matrix is diagonal\n");
   }
   else
   {
       fprintf(stderr, "your matrix is not diagonal\n");
   }
    return 0;
}
int diagonalCheck(int mat[MAX][MAX], int *v)
{
    int i, j;
    *v = 1;
    for(i = 0; i < MAX-1; i++)
    {
        for(j= 0; j < MAX-1; j++)
        {
            if(i == j && mat[i][j] != mat[i+1][j+1])
            {
                *v = 0;
            }
        }
    }
    return *v;
}