#include <stdio.h>
#include <string.h>

int howManyChars(char string[], int N);
int main() {
    char array[20];
    int a;

    gets(array);

    a = howManyChars(array, strlen(array));
    printf("%d chars", a);
    return 0;
}
int howManyChars(char string[], int N)
{
    int i;
    int count_spaces = 0;
    int count_char = 0;

    for(i = 0; i < N; i++)
    {
        if(string[i] == 32) // ascii code of space character
        {
            count_spaces++;
        }
        count_char++;
    }
    return (count_char - count_spaces);
}