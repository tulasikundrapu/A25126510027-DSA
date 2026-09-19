#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node* createNode(int value)
{
    struct Node *newNode=malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;
  return newNode;
}
struct Node* insert(struct Node *root, int value) 
{
    if(root==NULL) 
    {
        return createNode(value);
    }
    if(value<root->data) 
    {
        root->left=insert(root->left,value);
    }
    else if(value>root->data) 
    {
        root->right=insert(root->right,value);
    }
    return root;
}
void inorder(struct Node *root) 
{
    if (root!=NULL) 
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void preorder(struct Node *root) 
{
    if (root!=NULL) 
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node *root) 
{
    if (root!=NULL) 
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
struct Node* search(struct Node *root, int value) 
{
    if (root==NULL || root->data==value) 
    {
        return root;
    }
    if(value<root->data) 
    {
        return search(root->left,value);
    }
    return search(root->right,value);
}
int main() 
{
    struct Node *root = NULL;
    int n,value,searchValue;
    printf("Enter the number of values:");
    scanf("%d",&n);
    printf("\nEnter %d unique integer values only:\n", n);
    for (int i=0;i<n;i++) 
    {
        scanf("%d",&value);
        root=insert(root,value);
    }
    printf("\nInorder Traversal: ");
    inorder(root);
    printf("\nPreorder Traversal: ");
    preorder(root);
    printf("\nPostorder Traversal: ");
    postorder(root);
    printf("\n\nEnter value to search: ");
    scanf("%d",&searchValue);
    if(search(root,searchValue)!=NULL) 
    {
        printf("%d exists in the Binary Search Tree.\n", searchValue);
    } 
    else
    {
        printf("%d does not exist in the Binary Search Tree.\n", searchValue);
    }

    return 0;
}