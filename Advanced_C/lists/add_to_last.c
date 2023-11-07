#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int key;
    struct node *next;
}Node;

void insertList(Node *the_list, int val);
void printList(Node *your_list);
int main(){
    Node *head;
    int value;
    head = (Node *)malloc(sizeof(Node ));

    if(head == NULL){
        fprintf(stderr, "Memory allocation error!");
        exit(EXIT_FAILURE);
    }

    head->key = 5;
    head->next = NULL;

    printf("which value do you want to insert into your list?\n");
    scanf("%d", &value);
    insertList(head, value);
    printList(head);
    return 0;
}
void insertList(Node *the_list, int val){
    Node *current = the_list;

    while(current->next != NULL)
    {
        current = current->next;
    }

    current->next = (Node *)malloc(sizeof(Node));
    current->next->key = val;
    current->next->next = NULL;
}
void printList(Node *your_list){
    Node *current = your_list;
    printf("\n**********\n");
    while(current != NULL)
    {
        printf("%d\n", current->key);
        current = current->next;
    }
}