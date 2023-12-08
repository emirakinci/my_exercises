#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int key;
    struct node *next;
}Node;

Node *create();
void buildList(Node **head, int *arr, int N);
void printList(Node *head);
void freeList(Node **head);
int main(void){
    Node *head;
    int buffer[] = {1, 3, 5, 7 ,9};
    int sz = sizeof(buffer)/sizeof(int);

    buildList(&head, buffer, sz);
    printList(head);
    freeList(&head);
}
Node *create()
{
    Node *a_node = malloc(sizeof(Node));
    if(a_node == NULL)
    {
        fprintf(stderr, "Memory allocation error!");
        exit(EXIT_FAILURE);
    }
    return a_node;
}
void buildList(Node **head, int *arr, int N)
{
    Node *current = create();
    Node *tmp_head = current;

    for(int j=0; j<N; j++)
    {
        current->key = arr[j];
        if(j+1 == N)
        {
            current->next = NULL;
        }
        else
        {
            current->next = create();
            current = current->next;
        }
    }

    *head = tmp_head;
}
void printList(Node *head)
{
    if(head == NULL)
    {
        return;
    }
    printf("%d\n", head->key);
    printList(head->next);
}
void freeList(Node **head)
{
    Node *tmp;
    while(*head != NULL)
    {
        tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
}