#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int key;
    struct node *next;
}Node;

Node *create()
{
    Node *new;
    new = malloc(sizeof(Node ));

    if(new == NULL)
    {
        fprintf(stderr, "Memory allocation error!!");
        exit(EXIT_FAILURE);
    }
    return new;
}

Node *dequeue(Node *tail, int val);
int main(void){

    return 0;
}
Node *dequeue(Node *tail, int val)
{
    Node *change;
    if(tail = tail->next) // we check if the queue contains only 1 element!!
    {
        free(tail); // if yes then we simply free it
        tail = NULL;
    }
    else // if the queue contains more than 1 element we do the following:
    {
        change = tail->next; // 10 20 30    // the temporary pointer stores the tail->next a.k.a. head
        tail->next = change->next; // now, tail->next points the next element after the head!!
        free(change); // we simply free the head
    }

    return tail;
}