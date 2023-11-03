#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int key;
    struct node *next;
}Node;

void push(Node **head, int val)
{
    Node *the_list;
    the_list = (Node *)malloc(sizeof(Node ));
    if(the_list == NULL)
    {
        fprintf(stderr, "Memory allocation error!!");
        exit(EXIT_FAILURE);
    }

    the_list->next = *head; // link the lists
    *head = the_list; // set the new one to head
    the_list->key = val; 
}
int pop(Node **head);
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
    push(&head, value);
    printList(head);
    printf("\nlater:\n###########\n");
    pop(&head);
    printList(head);
    return 0;
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
int pop(Node **head)
{
    Node *following = NULL;
    int following_value;

    if(*head == NULL)
    {
        return -1;
    }

    following = (*head)->next;
    following_value = (*head)->key;
    free(*head);
    *head = following;

    return following_value;
}