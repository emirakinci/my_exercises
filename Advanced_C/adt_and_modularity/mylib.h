#ifndef mylib
#define mylib

#include <stdio.h>
#include <stdlib.h>
#define N 6
#define input "input.txt"

typedef struct data{
    int r;
    int c;
    int rep;
}Data;

void alloc_mat(char ***mat); //ok
void check(char **m, int n); //ok
void check_c(char **m, int n, Data *my_data); //ok
void print_result(char **m, int n, Data *my_data);

#endif