#include "mylib.h"

int main(int argc, char **argv){
    char **matrix;
    alloc_mat(&matrix);
    check(matrix, N);
    return 0;
}
