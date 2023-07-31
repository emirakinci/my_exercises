#include <stdio.h>
#include <string.h>
int removeChar(char v[], int pos[]);
int main(void)
{
    int nums[] = {7, 4, 2, 0, 11, -1};
    char str[] = "ThisIsAString";

    int r;
    r = removeChar(str, nums);

   printf("%d chars removed", r);

    return 0;
}
int removeChar(char v[], int pos[])
{
    int len = strlen(v);
    int i, j;
    int count_removed = 0;
    i = 0;

    while (pos[i] != -1)
    {
        if(pos[i] > pos[i+1])
        {
            for(j = pos[i]; j < len; j++)
            {
                v[j] = v[j+1];
            }
            len--;
            i++;
            count_removed++;
        }
        else
        {
            pos[i+1] -= count_removed+1;
            for(j = pos[i]; j < len; j++)
            {
                v[j] = v[j+1];
            }
            len--;
            i++;
            count_removed++;
        }
    }
    printf("%s\n", v);
    return count_removed;
}