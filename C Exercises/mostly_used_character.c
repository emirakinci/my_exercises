#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 25+1

void findMostlyUsed(char str[], int N);
int main() {
    char array[] = "GalataSaray";

    findMostlyUsed(array, strlen(array));
    return 0;
}
void findMostlyUsed(char str[], int N)
{
    char alphabet[LEN];
    int alp_values[LEN];
    int i, j, max;
    char c;

    for(c = 'a', i = 0; c<='z' && i < LEN; c++, i++)
    {
        alphabet[i] = c; //abcdefghijklmnopqrstuvwxyz
        alp_values[i] = 0;
    }

    for(i = 0 ; i < N; i++)
    {
        for(j = 0; j < LEN; j++)
        {
            if(tolower(str[i]) == alphabet[j])
            {
                alp_values[j]++;
            }
        }
    }

    max = 0;

    for(i = 0; i < LEN; i++)
    {
        if(alp_values[i] > alp_values[max])
        {
            max = i;
        }
    }
    printf("the mostly used character is '%c' with number of repetition '%d'", alphabet[max], alp_values[max]);
}