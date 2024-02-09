#include <stdio.h>
#include <stdlib.h>
#define N 5

typedef struct node{
    int key;
    struct node *next;
    struct node *prev;
}Node;

Node *create();
void linkLR(Node **head, int num);
void printList(Node *head);
int main(void)
{
    Node *head = NULL;
    int arr[N] = {10, 9, 8, 7, 6};
    for(int i=0; i<N; i++)
    {
        linkLR(&head, arr[i]);
    }
    printList(head);
    return 0;
}
Node *create()
{
    Node *new_node = malloc(sizeof(Node));
    if(new_node == NULL)
    {
        fprintf(stderr, "Memory allocation error");
        exit(EXIT_FAILURE);
    }

    return new_node;
}
void linkLR(Node **head, int num)
{
    Node *new_node = create();

    new_node->key = num;
    new_node->next = new_node->prev = NULL;

    if(*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        Node *tmp = *head;

        while(tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = new_node; // it is all about these parts 
        new_node->prev = tmp; // we link back and forward that is all
    }
}
void printList(Node *head)
{
    while(head != NULL)
    {
        printf("%d ", head->key);
        head = head->next;
    }
    printf("\n");
}