#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_CHAR 1000

typedef struct node{
    char *word;
    int frequency;
    struct node *next;
}Node;

Node *create(){
    Node *new_node = malloc(sizeof(Node ));
    if(new_node == NULL)
    {
        fprintf(stderr, "Memory allocation error!");
        exit(EXIT_FAILURE);
    }
    return new_node;
}
int checkWords(char *w1, char *w2);
Node *tailInsert(Node *the_head, char *val);
Node *readFile(char *fileName);
void writeFile(char *fileName, Node *headd)
{
    FILE *doc1 = fopen(fileName, "w");
    Node *current = headd;
    if(doc1 == NULL)
    {
        fprintf(stderr, "File opening error!");
        exit(EXIT_FAILURE);
    }
    while(current != NULL)
    {
        fprintf(doc1, "%s %d\n", current->word, current->frequency);
        current = current->next;
    }

    fclose(doc1);
}
void freeList(Node *first)
{
    Node *tmp;
    while(first != NULL)
    {
        tmp = first;
        first = first->next; 
        free(tmp);
    }
}
int main(int argc, char *argv[]){
    if(argc < 2)
    {
        fprintf(stderr, "The number of files is lower than the expected!\n");
        exit(EXIT_FAILURE);
    }
    Node *ptr = readFile(argv[1]);
    writeFile(argv[2], ptr);
    freeList(ptr);
    return 0;
}
int checkWords(char *w1, char *w2)
{
    if(strlen(w1) != strlen(w2))
    {
        return 0;
    }

    for(int i=0; i < strlen(w1); i++)
    {
        if(w1[i] != tolower(w2[i]))
        {
            return 0;
        }
    }
    return 1;
}
Node *readFile(char *fileName) {
    FILE *doc;
    Node *head = NULL;
    int counter = 0, flag;
    char buff[MAX_CHAR + 1];
    doc = fopen(fileName, "r");

    if (doc == NULL) {
        fprintf(stderr, "Error opening file: %s\n", fileName);
        exit(EXIT_FAILURE);
    }

    while ((fscanf(doc, "%s", buff)) != EOF) {
        Node *current = head; // better to use like that
        flag = 0;

        while (current != NULL) { // implementation of this loop is forgotten
            if (checkWords(current->word, buff) == 1) {
                current->frequency++;
                flag = 1;
                break;
            }
            current = current->next;
        }

        if (flag == 0) {
            head = tailInsert(head, buff);
            counter++;
        }
    }
    fclose(doc);
    return head;
}

Node *tailInsert(Node *the_head, char *val)
{
    if(the_head == NULL)
    {
        Node *head = create();
        head->word = malloc((strlen(val)+1)*sizeof(char)); // I forgot paranthesis
        strcpy(head->word, val);
        head->frequency = 1; // it is better to initalise to 1 
        head->next = NULL;

        return head;
    }
    Node *current = the_head;

    while(current->next != NULL)
    {
        current = current->next;
    }
    current->next = malloc(sizeof(Node ));
    current->next->word = malloc((strlen(val) + 1) * sizeof(char));
    strcpy(current->next->word, val);

    current->next->frequency = 1;
    current->next->next = NULL;

    return the_head; // I should have returned head!!
}
