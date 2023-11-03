#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int key;
    struct node *next;
}Node;

Node *generate_node()
{
    Node *a_node;

    a_node = (Node *)malloc(sizeof(Node ));
    if(a_node == NULL)
    {
        fprintf(stderr, "Memory allocation error!\n");
        exit(EXIT_FAILURE);
    }
    return a_node;
}
void freeList(Node *first);
void printList(Node *first);
int main(){

    Node *head = generate_node(), *second = generate_node();
    int x = 5, y = 15;
    head->key = x;
    second->key = y;

    head->next = second;
    second->next = NULL;

    printf("before:\n**********\n");
    printList(head);
    freeList(head);
    printf("after:\n**********\n");
    printList(head);
}
void printList(Node *first){
    Node *current = first;

    while (first != NULL)
    {
        printf("%d\n", first->key);
        first = first->next;
    }
}
void freeList(Node *first)
{
    Node *tmp;
    //first is head!
    while(first != NULL)
    {
        // the strategy is we start from freeing the first node till the last. With the tmp we store each node and free them.
        // i.e. we go from the left most element to the right most one.
        tmp = first;
        first = first->next; 
        free(tmp);
    }
}