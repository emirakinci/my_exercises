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
    a_node->next = NULL;

    return a_node;
}
void push(Node **head, int val);
void printList(Node *your_list);
int main(){
    Node *head = generate_node(), *second = generate_node();
    int x = 5, y = 15, z = 99;
    head->key = x;
    second->key = y;

    head->next = second;
    second->next = NULL;
    // we insert 99 on top of the list!
    push(&head, z);
    printList(head);
    return 0;
}
void push(Node **head, int val){
    Node *new_node;
    new_node = (Node *)malloc(sizeof(Node ));

    new_node->key = val;// Create a new item and set its value
    new_node->next = *head; // Link the new item to point to the head of the list
    *head = new_node; // Set the head of the list to be our new item
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
// 2 3 4 5 6 7 8 9