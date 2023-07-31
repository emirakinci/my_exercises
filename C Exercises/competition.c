#include <stdio.h>
#define REF 10
struct competitor{
    char name[20], surname[25];
    float points_taken[REF], performance;
};
float calculatePoints(float array[]);
int main() {

    int num_of_competitors, i, j;
    printf("how many competitors do we have?\n");
    scanf("%d", &num_of_competitors);

    struct competitor competitors[num_of_competitors];

    for(i = 0; i < num_of_competitors; i++)
    {
        printf("name:\n");
        scanf("%s", &competitors[i].name);
        printf("surname:\n");
        scanf("%s", &competitors[i].surname);

        for(j = 0; j < REF; j++)
        {
            printf("%d. ref your pts:\n", j+1);
            scanf("%f", &competitors[i].points_taken[j]);
        }
        competitors[i].performance = calculatePoints(competitors[i].points_taken);
    }

    for(i = 0; i < num_of_competitors; i++)
    {
        printf("%s %s = %.2f\n", competitors[i].name, competitors[i].surname, competitors[i].performance);
    }
    return 0;
}
float calculatePoints(float array[])
{
    int i;
    float sum = 0;
    float max = array[0], min = array[0];
    for(i = 0; i < REF; i++)
    {
        if(array[i] > max)
        {
            max = array[i];
        }
        if(array[i] < min)
        {
            min = array[i];
        }
        sum+=array[i];
    }

    return ((sum - (max + min))/(REF - 2));
}