#include <stdio.h>
#include <stdlib.h>
#define N 5
typedef struct node{
    int key;
    struct node *next;
}Node;

Node *new_element()
{
    Node *a_node = (Node *)malloc(sizeof(Node ));
    if(a_node == NULL)
    {
        fprintf(stderr, "Memory allocation error!");
        exit(EXIT_FAILURE);
    }

    return a_node;
}
Node *headInsert(Node *head, int val);
Node *headExtract(Node *head);
void printStack(Node *head);
Node *freeStack(Node *head);
int main(void){
    Node *my_head = new_element();
    int x = 15, i;
    my_head->key = x;
    my_head->next = NULL;

    for(i = 0; i < N; i++)
    {
        my_head = headInsert(my_head, i+1);
    }
    printStack(my_head);
    printf("\n*********\n\n");
    my_head = headExtract(my_head);
    printStack(my_head);
    my_head = freeStack(my_head);
    return 0;
}
Node *headInsert(Node *head, int val)
{
    Node *new = new_element();
    new->key = val;
    new->next = head;
    head = new;

    return head;
}
Node *headExtract(Node *head)
{
    Node *change = NULL;
    if(head == NULL)
    {
        fprintf(stderr, "The list is empty extraction can't be performed!!");
        exit(EXIT_FAILURE);
    }
    change = head->next;
    free(head);
    head = change;

    return head;
}
void printStack(Node *head)
{
    Node *current = head;

    while(current != NULL)
    {
        printf("%d\n", current->key);
        current = current->next;
    }
}
Node *freeStack(Node *head)
{
    Node *tmp;

    while(head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
    printf("\nThe stack has been freed successfully!");
    return head;
}