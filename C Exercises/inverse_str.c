#include <stdio.h>
#include <string.h>
void inverse(char *arr, int N);
int main(void){
    char arr_c[] = "-YOUR_STR-";
    int sz = sizeof(arr_c)-1;
    inverse(arr_c, sz);
    printf("%s", arr_c);
    return 0;
}
void inverse(char *arr, int N){
    int i;
    char temp;
    
    for(i=0; i<N/2; i++)
    {
        temp = arr[i];
        arr[i] = arr[N-i-1];
        arr[N-i-1] = temp;
    }
}