#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_RECTANGLE 100
#define WORD_LENGTH 4

struct point{
    float x;
    float y;
};
typedef struct rectangles{
    char rid[WORD_LENGTH+1];
    struct point first_point;
    struct point second_point;
    float area;
    float perimeter;
}Rectangle;

float computeArea(struct point p1, struct point p2);
float computePerimeter(struct point p1, struct point p2);
int readFile(char *fileName, Rectangle my_rectangles[]);
void areaInsert(Rectangle my_rectangles[], char *fileName, int n);
void perimeterInsert(Rectangle my_rectangles[], char *fileN, int m);

int main(int argc, char *argv[]){
    if(argc < 3)
    {
        fprintf(stderr, "number of input is not sufficient!");
        exit(EXIT_FAILURE);
    }
    Rectangle the_rectangles[MAX_RECTANGLE];
    int N = readFile(argv[1], the_rectangles);
    areaInsert(the_rectangles, argv[2], N);
    perimeterInsert(the_rectangles, argv[3], N);
    return 0;
}
int readFile(char *fileName, Rectangle my_rectangles[])
{
    FILE *doc = fopen(fileName, "r");
    int index = 0;
    char scode[MAX_RECTANGLE][WORD_LENGTH+1];
    float x, y;
    int flag = -1;

    if(doc == NULL)
    {
        fprintf(stderr, "File not found!");
        exit(EXIT_FAILURE);
    }

    while(!feof(doc))
    {
        fscanf(doc, "%s%f%f", scode[index], &x, &y);
        for(int i = 0; i < index; i++)
        {
            if(strcmp(scode[index], my_rectangles[i].rid) == 0) // found
            {
                flag = i;
                break;
            }
            else
            {
                flag = -1;
            }
        }
        if(flag!=-1)
        {
            my_rectangles[flag].second_point.x = x;
            my_rectangles[flag].second_point.y = y;

            my_rectangles[flag].area = computeArea(my_rectangles[flag].first_point, my_rectangles[flag].second_point);
            my_rectangles[flag].perimeter = computePerimeter(my_rectangles[flag].first_point, my_rectangles[flag].second_point);
        }
        else
        {
            strcpy(my_rectangles[index].rid, scode[index]);
            my_rectangles[index].first_point.x = x;
            my_rectangles[index].first_point.y = y;
            index++;
        }
    }
    fclose(doc);
    return index;
}
float computeArea(struct point p1, struct point p2)
{
    float x_differences, y_differences;

    x_differences = fabs(p1.x - p2.x);
    y_differences = fabs(p1.y - p2.y);
    return x_differences * y_differences;
}
float computePerimeter(struct point p1, struct point p2)
{
    float x_axis, y_axis;
    
    y_axis = fabs(p1.y - p2.y);
    x_axis = fabs(p1.x - p2.x);

    return(2*y_axis + 2*x_axis);
}
void areaInsert(Rectangle my_rectangles[], char *fileName, int n)
{
    FILE *doc;
    Rectangle tmp;
    int i, j;

    doc = fopen(fileName, "w");

    for(i = 1; i < n; i++)
    {
        tmp = my_rectangles[i];
        j = i-1;

        while(j>=0 && tmp.area > my_rectangles[j].area)
        {
            my_rectangles[j+1] = my_rectangles[j];
            j--;
        }
        my_rectangles[j+1] = tmp;
    }

    for(i = 0; i < n; i++)
    {
        fprintf(doc, "%s\n", my_rectangles[i].rid);
    }
    fclose(doc);
}
void perimeterInsert(Rectangle my_rectangles[], char *fileN, int m)
{
    FILE *doc2 = fopen(fileN, "w");
    Rectangle tmp;
    int i, j;

    for(i = 1; i < m; i++)
    {
        tmp = my_rectangles[i];
        j = i-1;

        while(j >= 0 && tmp.perimeter > my_rectangles[j].perimeter)
        {
            my_rectangles[j+1] = my_rectangles[j];
            j--;
        }
        my_rectangles[j+1] = tmp;
    }

    for(i = 0; i < m; i++)
    {
        fprintf(doc2, "%s\n", my_rectangles[i].rid);
    }
    fclose(doc2);
}