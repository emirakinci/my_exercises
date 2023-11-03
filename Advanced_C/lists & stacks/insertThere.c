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
int elementCount(Node *first)
{
    int counter = 0;
    for(Node *current = first; current != NULL; current = current->next)
    {
        counter++;
    }
    return counter;
}
void insertThere(Node **first, int val, int index);
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
    Node *head = create(), *second = create(), *third = create();
    int x = 5, y = 15, z = 31, q;
    int pos;

    printf("which value do you want to insert & position?\n");
    scanf("%d%d", &q, &pos);

    head->key = x;
    second->key = y;
    third->key = z;

    head->next = second;
    second->next = third;
    third = second;

    insertThere(&head, q, pos);
    printList(head);
    freeList(head);
    return 0;
}
void insertThere(Node **first, int val, int index)
{
    Node *current = *first, *temp, *new_node;
    int i;

    if(index == elementCount(current) + 1 || index == 0)
    {
        fprintf(stderr, "this function can not perform insertion on the given indexes!");
        exit(EXIT_FAILURE);
    }

    new_node = create();
    new_node->key = val;
    // 1 2 3 4 5 6 7 
    for(i = 0; i < index-1; i++)
    {
        current = current->next;
    }
    temp = current->next;
    current->next = new_node;
    new_node->next = temp;
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
// altrettanto