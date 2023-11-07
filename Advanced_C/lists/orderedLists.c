#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int key;
    struct node *next;
}Node;

Node *create(){

    Node *my_node = (Node *)malloc(sizeof(Node ));
    if(my_node == NULL)
    {
        fprintf(stderr, "Memory allocation error!");
        exit(EXIT_FAILURE);
    }
    return my_node;
}

Node *insertTail(Node *first, int val);
int search(Node *list, int val);
void printList(Node *my_head);
Node *freeList(Node *the_head);

int main(void){
    Node *head = create();
    head->key = 1;

    int i, N, v, the_index;

    printf("how many do you want to insert?\n");
    scanf("%d", &N);
    printf("*****\n");

    for(i = 0; i < N; i++)
    {
        head = insertTail(head, i+2);
        if(i == 3)
        {
            i++;
        }
    }

    printList(head);
    printf("****\n****\n");
    printf("which value are you looking for ?\n");
    scanf("%d", &v);

    the_index = search(head, v);

    if(the_index == -1)
    {
        printf("Your number is not included in the list!");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("\n%d is at %d. index\n", v, the_index);
    }
    freeList(head);
    return 0;
}
Node *insertTail(Node *first, int val)
{
    Node *current = first;

    while(current->next != NULL)
    {
        current = current->next;
    }

    current->next = malloc(sizeof(Node ));
    current->next->key = val;
    current->next->next = NULL;

    return first;
}
void printList(Node *my_head)
{
    Node *current = my_head;

    while(current != NULL)
    {
        printf("%d\n", current->key);
        current = current->next;
    }
}
Node *freeList(Node *the_head)
{
    Node *tmp;

    while(the_head != NULL)
    {
        tmp = the_head;
        the_head = the_head->next;
        free(tmp);
    }
    return the_head;
}
int search(Node *list, int val)
{
    Node *current = list;
    int index = 0;

    while(current != NULL && val > current->key)
    {
        index++;
        current = current->next;
    }
    if(current != NULL && val == current->key)
    {
        return index;
    }
    return -1;
}