#include <stdio.h>
#include <string.h>
void reversePrint(char *word, int l, int r);
void reversePrint2(char *word);
int main(void){
    char arr[] = "GALATASARAY";
    printf("%s == ", arr);
    //reversePrint(arr, 0, strlen(arr)-1);
    reversePrint2(arr);
    return 0;
}
void reversePrint(char *word, int l, int r)
{
    if(r == l)
    {
        printf("%c", word[r]);
        return ;    
    }
    printf("%c", word[r]);
    reversePrint(word, l, r-1);
}
void reversePrint2(char *word)
{
    if(*word == '\0')
    {
        return;
    }
    reversePrint2(word+1);
    printf("%c", *word);
    return ;
}