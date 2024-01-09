//find the max and min nodes in a bst
#include <stdio.h>
#include <stdlib.h>
#define N 5

typedef struct bst{
    int key;
    struct bst *l, *r;
}Node;

Node *create(int val); 
Node *insertTree(int value, Node *root);
Node *min_node(Node *root);
Node *max_node(Node *root);
void inorder_print(Node *root);

int main(void)
{
    int i = 1;
    int values[N] = {15, 10, 5, 23, 2};
    int rm_val;
    Node *root = create(values[0]);
    Node *min, *max;

    while(i < N)
    {
        root = insertTree(values[i], root);
        i++;
    }
    //inorder_print(root);
    min = min_node(root);
    max = max_node(root);

    printf("min node is : %d\n", min->key);
    printf("max node is : %d", max->key);
}
Node *create(int val)
{
    Node *root = (Node *)malloc(sizeof(Node));
    if(root == NULL)
    {
        fprintf(stderr, "Error allocating the node!");
        exit(EXIT_FAILURE);
    }

    root->key = val;
    root->l = root->r = NULL;

    return root;
}
Node *insertTree(int value, Node *root)
{
    if(root == NULL)
    {
        return(create(value));
    }

    if(value < root->key)
    {
        root->l = insertTree(value, root->l);
    }
    if(value > root->key)
    {
        root->r = insertTree(value, root->r);
    }
    return root;
}
Node *min_node(Node *root)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->l == NULL)
    {
        return root;
    }
    return min_node(root->l);
}
Node *max_node(Node *root)
{
    if(root == NULL)
    {
        return NULL;
    }
    if(root->r == NULL)
    {
        return root;
    }
    return min_node(root->r);

}
void inorder_print(Node *root)
{
    if(root == NULL)
    {
        return ;
    }
    inorder_print(root->l);
    printf("%d ", root->key);
    inorder_print(root->r);
}