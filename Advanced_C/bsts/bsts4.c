//delete a given node in the bst
#include <stdio.h>
#include <stdlib.h>
#define N 5

typedef struct bst{
    int key;
    struct bst *l, *r;
}Node;

Node *create(int val); // a function for creating a node
Node *insertTree(int value, Node *root); // a function for inserting a node to the tree
Node *remove_node(int value, Node *root); // a function for removing a node from the tree
void inorder_print(Node *root);

int main(void)
{
    int i = 1;
    int values[N] = {15, 10, 5, 23, 2};
    int rm_val;
    Node *root = create(values[0]);

    while(i < N)
    {
        root = insertTree(values[i], root);
        i++;
    }
    printf("before deletion:\n");
    inorder_print(root);

    printf("after the deletion:\n");
    root = remove_node(rm_val, root);
    inorder_print(root);
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
Node *remove_node(int value, Node *root)
{
    if(root == NULL)
    {
        return root;
    }

    if(value < root->key)
    {
        root->l = insertTree(value, root->l);
    }
    else if(value > root->key)
    {
        root->r = insertTree(value, root->r);
    }
    else
    {
        if(root->l == NULL && root->r == NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->l == NULL || root->l == NULL )
        {
            Node *tmp;
            if(root->l == NULL)
            {
                tmp = root->r;
            }
            else
            {
                tmp = root->l;
            }
            free(root);

            return tmp;
        }
        // find the min in lst and 
    }
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