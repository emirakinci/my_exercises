#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int key;
    struct node *next;
}Node;

typedef struct ListOfLists{
    Node *sublist;
    struct ListOfLists *next;
}ListOfLists;

Node *create_list(int val);
ListOfLists *create_lol(Node *arr);
void printLol(ListOfLists *lol);

int main(void){
    Node *ll1 = create_list(15);
    ll1->next = create_list(8);
    ll1->next->next = create_list(5);

    Node *ll2 = create_list(30);
    ll2->next = create_list(9);
    ll2->next->next = create_list(7);

    Node *ll3 = create_list(99);
    ll3->next = create_list(37);
    ll3->next->next = create_list(51);
    // now we create the list moving downwards

    ListOfLists *lol1 = create_lol(ll1);
    lol1->next = create_lol(ll2);
    lol1->next->next = create_lol(ll3);
    printLol(lol1);
    return 0;
}
Node *create_list(int val)
{
    Node *new_node = malloc(sizeof(Node));
    if(new_node == NULL)
    {
        fprintf(stderr, "Memory allocation error!");
        exit(EXIT_FAILURE);
    }

    new_node->key = val;
    new_node->next = NULL;

    return new_node;
}
ListOfLists *create_lol(Node *arr)
{
    ListOfLists *new_lol = malloc(sizeof(ListOfLists));
    if(new_lol == NULL)
    {
        fprintf(stderr, "Memory allocation error!");
        exit(EXIT_FAILURE);
    }
    new_lol->sublist = arr;
    new_lol->next = NULL;

    return new_lol;
}
void printLol(ListOfLists *lol)
{
    ListOfLists *loltmp = lol;

    while(loltmp != NULL)
    {
        Node *ltmp = loltmp->sublist;
        while(ltmp != NULL)
        {
            fprintf(stdout, "%d ", ltmp->key);
            ltmp = ltmp->next;
        }
        printf("\n");
        loltmp = loltmp->next;
    }
}