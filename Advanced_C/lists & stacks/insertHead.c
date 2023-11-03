#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int key;
    struct node *next;
}Node;

Node *create(){
    Node *a_node;
    a_node = (Node *)malloc(sizeof(Node ));

    if(a_node == NULL)
    {
        fprintf(stderr, "Memory allocation error!");
        exit(EXIT_FAILURE);
    }
    a_node->next = NULL;
    return a_node;
}
void push(Node **list, int val);
void printList(Node *first);
void freeList(Node *first)
{
    Node *tmp;
    while (first != NULL)
    {
        tmp = first;
        first = first->next;
        free(tmp);
    }
}
int main(void){
    Node *head = create(), *second = create();
    int x = 5, y = 15, z = 31;

    head->key = x;
    second->key = y;
    head->next = second;
    second = head;
    push(&head, z);
    printList(head);
    freeList(head);
    return 0;
}
void push(Node **list, int val)
{
    Node *new_node = (Node *)malloc(sizeof(Node ));
    new_node->key = val;
    new_node->next = *list; // Make next of new node as head
    *list = new_node;  // Move the head to point to the new node
}
void printList(Node *first)
{
    Node *current = first;

    while(current != NULL)
    {
        printf("%d\n", current->key);
        current = current->next;
    }
}