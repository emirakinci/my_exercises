#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int key;
    struct node *next;
}Node;


Node *create()
{
    Node *head;
    head = (Node *)malloc(sizeof(Node ));

    if(head == NULL)
    {
        fprintf(stderr, "Memory allocation error!!");
        exit(EXIT_FAILURE);
    }
    head->next = NULL;
    return head;
}
void insertTail(Node *head, int val);
void printList(Node *first);
void freeList(Node *head);
int main(void){

    Node *head = create();
    Node *second = create();

    int x = 15, y = 5;
    int z = 37;
    // assigning the values to my lists
    head->key = x;
    second->key = y;
    // linking my lists
    head->next = second;
    second = head;

    insertTail(head, z);
    printList(head);
    freeList(head);
    return 0;
}
void printList(Node *first){
    Node *current = first;

    while(current != NULL)
    {
        printf("%d\n", current->key);
        current = current->next;
    }   
}
void insertTail(Node *head, int val){
    Node *current = head;

    while(current->next != NULL)
    {
        current = current->next;
    }
    current->next = (Node *)malloc(sizeof(Node ));
    current->next->next = NULL;
    current->next->key = val;
}
void freeList(Node *head){
    Node *tmp;

    while(head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
    printf("freed successfully!\n");
    exit(EXIT_SUCCESS);
}