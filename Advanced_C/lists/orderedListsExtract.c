#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int key;
    struct node *next;
}Node;

Node *create(){
    Node *a_node = malloc(sizeof(sizeof(Node )));
    if(a_node == NULL)
    {
        fprintf(stderr, "Memory allocation error!");
        exit(EXIT_FAILURE);
    }
    return a_node;
}
Node *insertTail(Node *first, int val);
void printList(Node *first);
Node *extract(Node *first, int val);
Node *freeList(Node *first);

int main(void){
    Node *head = create();
    int i, N, num;
    head->key = 5;

    printf("how many numbers do you want to insert?\n");
    scanf("%d", &N);

    for(i = head->key; i < N+head->key; i++)
    {
        head = insertTail(head, i+2);
    }
    printList(head);


    printf("which number do you want to insert?\n");
    scanf("%d", &num);

    head = insertNumber(head, num);
    printf("\n*******\n");
    printList(head);

    head = freeList(head);

    return 0;
}
Node *insertTail(Node *first, int val){
    Node *current = first;
    while(current->next != NULL)
    {
        current = current->next;
    }
    current->next = (Node *)malloc(sizeof(Node ));
    current->next->key = val;
    current->next->next = NULL;

    return first;
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
Node *extract(Node *first, int val)
{
    Node *q = first, *temp;
    if(first == NULL) // check if the list is empty
    {
        fprintf(stderr, "The list is empty!!\n");
        exit(EXIT_FAILURE);
    }
    if(val == first->key) // head extraction if value is found on the head
    {
        temp = first->next;
        free(first);
        return temp;
    }
    while(q->next != NULL && val > q->next->key) // begin searching
    {
        q = q->next;
    }

    if(q->next != NULL && val == q->next->key) // extraction step
    {
        temp = q->next;
        q->next = temp->next;
        free(temp);
    }
    else // if element not contained in the list raise an error
    {
        fprintf(stderr, "Element not found!!");
        exit(EXIT_FAILURE);
    }
    return first;
}
Node *freeList(Node *first){
    Node *tmp;

    while(first != NULL)
    {
        tmp = first;
        first = first->next;
        free(tmp);
    }
    return first;
}