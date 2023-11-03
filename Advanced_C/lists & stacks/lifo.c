#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int key;
    struct node *next;
}Node;

Node *new_element()
{
    Node *new_node;
    new_node = (Node *)malloc(sizeof(Node ));
    if(new_node == NULL)
    {
        fprintf(stderr, "Memory allocation error!\n");
        exit(EXIT_FAILURE);
    }
    return new_node;
}

Node *push(Node *top, int val);
Node *pop(Node *top)
{
    Node *next_node = NULL;

    if(top == NULL)
    {
        fprintf(stderr, "The list is null extraction can't be performed!\n");
        exit(EXIT_FAILURE);
    }
    next_node = top->next; // the next item that head points is stored!
    free(top); // free the head
    top = next_node; // Set the head to be the next item that we've stored on the side
    return top;
}
void printList(Node *head);
Node *freeStack(Node *head);
int main(void){

    Node *last = new_element();
    last->next = NULL;
    last->key = 99;

    last = push(last, 15);
    printList(last);
    last = pop(last);
    printf("*******\n");
    printList(last);
    last = freeStack(last);
    return 0;
}
Node *push(Node *top, int val)
{
    Node *new;
    new = new_element();
    new->key = val; // 1
    new->next = top; // 2
    top = new; // 3
    
    return top; // we return top because after operation number 3 the top points to new.
}
void printList(Node *head)
{
    Node *current;
    for(current = head; current != NULL; current = current->next)
    {
        printf("%d\n", current->key);
    }
}
Node *freeStack(Node *head){
    Node *tmp;
    while(head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
    printf("\n#Successfully freed!!#");
    return head;
}
