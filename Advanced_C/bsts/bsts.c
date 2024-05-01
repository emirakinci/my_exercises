#include <stdio.h>
#include <stdlib.h>
#define N 6

typedef struct bsts{
    int key;
    struct bsts *l, *r;
}Node;

Node *create_node(int val);
Node *insert_node(int num, Node *root);
Node *remove_node(int num, Node *root);

void inorder_print(Node *root);
void freeBst(Node *root);

int main(void){

    Node *root;
    int vals[] = {15, 10, 20, 30, 5, 9};
    int i = 1;
    int rm_val;

    root = create_node(vals[0]);
    root = insert_node(vals[0], root);
    while(i < N)
    {
        insert_node(vals[i], root);
        i++;
    }
    printf("in-order:");
    inorder_print(root);
    printf("\nThe numbers are successfully inserted!\n");
    printf("whihc number do you wanna remove?");
    scanf("%d", &rm_val);

    freeBst(root);
}
Node *create_node(int val)
{
    Node *nd = malloc(sizeof(Node));
    if(nd == NULL)
    {
        fprintf(stderr, "Node allocation error!");
        exit(EXIT_FAILURE);
    }
    nd->key = val;
    nd->r = nd->l = NULL;
    return nd;
}
Node *insert_node(int num, Node *root)
{
    if(root == NULL)
    {
        return(create_node(num));
    }

    if(num < root->key)
    {
        root->l = insert_node(num, root->l);
    }
    if(num > root->key)
    {
        root->r = insert_node(num, root->r);
    }

    return root;
}
void inorder_print(Node *root)
{
    if(root == NULL)
    {
        return ;
    }
    inorder_print(root->l);
    inorder_print(root->r);
    printf(" %d", root->key);
}
void freeBst(Node *root)
{
    if(root == NULL)
    {
        return ;
    }
    freeBst(root->l);
    freeBst(root->r);

    free(root);
}
Node *remove_node(int num, Node *root)
{
    Node *p;

    if(root == NULL)
    {
        return root;
    }
    if(num > root->key)
    {
        root->r = remove_node(num, root->r);
        return root;
    }
    if(num < root->key)
    {
        root->l = remove_node(num, root->l);
        return root;
    }

    p = root;
    if(root->r == NULL)
    {
        root = root->l;
        free(p);
        return root;
    }
    if(root->l == NULL)
    {
        root = root->r;
        free(p);
        return root;
    }

    return root;
}