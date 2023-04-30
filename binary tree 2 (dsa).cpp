#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* create()
{
    struct node *newnode;
    int x;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &x);
    if(x == -1)
    {
        return NULL;
    }
    else
    {
        newnode->data = x;
        printf("Enter left child of %d:\n", x);
        newnode->left = create();
        
        printf("Enter right child of %d:\n", x);
        newnode->right = create();
        return newnode;
    }
}

void preorder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void inorder(struct node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    struct node *root = NULL;
    printf("Enter elements of the binary tree:\n");
    root = create();
    
    printf("Sequence of preorder traversal (root, left, right):\n");
    preorder(root);
    printf("\n");
    
    printf("Sequence of postorder traversal (left, right, root):\n");
    postorder(root);
    printf("\n");
    
    printf("Sequence of inorder traversal (left, root, right):\n");
    inorder(root);
    printf("\n");
    
    return 0;
}

