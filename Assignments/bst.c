#include<stdio.h>
#include<stdlib.h>
struct Node 
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node* createNode(int data) 
{
    struct Node* newNode=malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
struct Node* insert(struct Node* root,int data) 
{
    if(root==NULL)
        return createNode(data);
    if(data<root->data)
        root->left=insert(root->left,data);
    else if(data>root->data)
        root->right=insert(root->right,data);
    return root;
}
struct Node* findMin(struct Node* root) 
{
    struct Node* current=root;
    while(current!=NULL && current->left!=NULL)
        current=current->left;
    return current;
}
struct Node* deleteNode(struct Node* root, int key) 
{
    if (root==NULL) 
    {
        return NULL;
    }
    if (key<root->data) 
    {
        root->left=deleteNode(root->left,key);
    }
    else if(key>root->data) 
    {
        root->right=deleteNode(root->right,key);
    }
    else 
    {
        if (root->left==NULL && root->right==NULL) 
        {
            free(root);
            return NULL;
        }
        if (root->left==NULL) 
        {
            struct Node* temp=root->right;
            free(root);
            return temp;
        }
        if (root->right==NULL) 
        {
            struct Node* temp=root->left;
            free(root);
            return temp;
        }
        struct Node* temp=findMin(root->right);
        root->data=temp->data;
        root->right=deleteNode(root->right,temp->data);
    }
    return root;
}
void inorder(struct Node* root) 
{
    if (root!=NULL) 
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void freeTree(struct Node* root) 
{
    if(root!=NULL) 
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() 
{
    struct Node* root = NULL;
    int n,val,key;
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    printf("Enter %d values:\n", n);
    for (int i=0;i<n;i++) 
    {
        scanf("%d",&val);
        root=insert(root, val);
    }
    printf("\nInorder traversal before deletion:\n");
    inorder(root);
    printf("\nEnter node to delete: ");
    scanf("%d", &key);
    root = deleteNode(root, key);
    printf("\nInorder traversal after deletion:\n");
    inorder(root);
    printf("\n");
    freeTree(root);
    return 0;
}
