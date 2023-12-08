#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int key;
    struct node *next;
}Node;

Node *create(){
    Node *a_node = malloc(sizeof(Node));
    if(a_node == NULL)
    {
        fprintf(stderr, "Memory allocation error!");
        exit(EXIT_FAILURE);
    }
    return a_node;
}

void createList(Node **head, int *array, int N);
void printList(Node *head);
void freeList(Node **head);
int main(void)
{
    Node *head;
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(int);
    createList(&head, arr, n); // copy the array to the list
    printList(head); // print the list
    freeList(&head); // lastly, free the list
    return 0;  
}
void createList(Node **head, int *array, int N)
{
    Node *current = create();
    Node *tmp_head = current;

    for(int i=0; i<N; i++)
    {
        current->key = array[i];
        if(i+1==N)
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
    Node *move = head;
    while(move != NULL)
    {
        printf("%d\n", move->key);
        move = move->next;
    }
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