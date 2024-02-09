#include <stdio.h>
#include <stdlib.h>
#define N 5

typedef struct node{
    int key;
    struct node *next;
}Node;

Node *create();
void create_circular(Node **head, int num);
void printList(Node *head);

int main(void){
    Node *head = NULL;
    int arr[N] = {15, 9, 8, 5, 30};
    int i;

    for(i=0; i<N; i++)
    {
        create_circular(&head, arr[i]);
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
    new_node->next = NULL;

    return new_node;
}
void create_circular(Node **head, int num)
{
    Node *current = create();
    current->key = num;

    if(*head == NULL)
    {
        *head = current;
        current->next = current;
    }
    else
    {
        Node *tmp = *head;
        while(tmp->next != *head)
        {
            tmp = tmp->next;
        }

        tmp->next = current;
        current->next = *head;
    }
}
void printList(Node *head)
{
    Node *temp = head;
    if(head != NULL)
    {
        do
        {
            printf("%d ", temp->key);
            temp = temp->next;
        } while(temp != head);
    }
}