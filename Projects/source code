#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
    int bookId;
    char title[50];
    char author[50];

    int available;
    int issueDay;
    int dueDay;

    struct Node *left;
    struct Node *right;

};
struct Node* createNode()
{
    struct Node* newNode = malloc(sizeof(struct Node));

    printf("Enter Book ID: ");
    scanf("%d",&newNode->bookId);

    printf("Enter Book Title: ");
    scanf(" %[^\n]",newNode->title);

    printf("Enter Author: ");
    scanf(" %[^\n]",newNode->author);

    newNode->available = 1;
    newNode->issueDay = 0;
    newNode->dueDay = 0;

    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}
struct Node* insert(struct Node *root, struct Node *newNode)
{
    if(root == NULL)
    {
        return newNode;
    }
    if(newNode->bookId < root->bookId)
    {
        root->left = insert(root->left,newNode);
    }
    else if(newNode->bookId > root->bookId)
    {
        root->right = insert(root->right, newNode);
    }
    else
    {
        printf("Book ID already exists!\n");
        free(newNode);
    }
    
    return root;
}
void inorder(struct Node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        
        printf("\nBook ID: %d", root->bookId);
        printf("\nTitle: %s", root->title);
        printf("\nAuthor: %s", root->author);

        if(root->available == 1)
            printf("\nStatus: Available\n");
        
        else
            printf("\nStatus: Issued\n");

        inorder(root->right);

    }
}
struct Node* search(struct Node *root,int id)
{
    if(root == NULL || root->bookId == id)
    {
        return root;
    }
    if(id < root->bookId)
    {
        return search(root->left, id);
    }
    else
    {
        return search(root->right, id);
    }
}
void issueBook(struct Node *root, int id)
{
    struct Node *book = search(root, id);

    if(book == NULL)
    {
       printf("\nBook not found!\n");
       return;
    }
    if(book->available == 0)
    {
       printf("\nBook is already issued!\n");
       return;
    }

    printf("\nEnter issue day: ");
    scanf("%d", &book->issueDay);

    int days;

    printf("Enter number of days allowed: ");
    scanf("%d",&days);

    book->dueDay  = book->issueDay + days;
    book->available = 0;
    
    printf("\nBook issued successfully!");
    printf("\nDue day: %d\n", book->dueDay);
}
void returnBook(struct Node *root, int id)
{
    struct Node *book = search(root, id);

    if(book == NULL)
    {
        printf("\nBook not Found\n");
        return;
    }
    if(book->available == 1)
    {
        printf("\nBook is already available");
        return;
    } 

    int returnDay;
    int lateDays;
    int fine;

    printf("\nEnter return day: ");
    scanf("%d",&returnDay);

    if(returnDay > book->dueDay)
    {
        lateDays = returnDay - book->dueDay;
        fine = lateDays * 1;
    }
    else{
        lateDays = 0;
        fine = 0;
    }
    book->available = 1;
    book->issueDay = 0;
    book->dueDay = 0;
    
    printf("\nBook returned successfully!");
    printf("\nLate days: %d", lateDays);
    printf("\nFine: Rs.%d\n", fine);

}
struct Node* findMin(struct Node *root)
{
    while(root->left != NULL)
    {
        root = root->left;
    }

    return root;
}
struct Node* deleteBook(struct Node *root, int id)
{
    if(root == NULL)
    {
        printf("\nBook not found!\n");
        return root;
    }

    if(id < root->bookId)
    {
        root->left = deleteBook(root->left, id);
    }
    else if(id > root->bookId)
    {
        root->right = deleteBook(root->right, id);
    }
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            printf("\nBook deleted successfully!\n");
            return NULL;
        }
        else if(root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            printf("\nBook deleted successfully!\n");
            return temp;
        }
        else if(root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            printf("\nBook deleted successfully!\n");
            return temp;
        }
        else
        {
            struct Node *temp = findMin(root->right);

            root->bookId = temp->bookId;
            strcpy(root->title, temp->title);
            strcpy(root->author, temp->author);
            root->available = temp->available;
            root->issueDay = temp->issueDay;
            root->dueDay = temp->dueDay;

            root->right = deleteBook(root->right, temp->bookId);
        }
    }

    return root;
}
void saveBooks(struct Node *root, FILE *fp)
{
    if(root != NULL)
    {
        fprintf(fp, "%d|%s|%s|%d|%d|%d\n", root->bookId, root->title ,root->author, root->available, root->issueDay, root->dueDay);

        saveBooks(root->left, fp);
        saveBooks(root->right, fp);
    }
}
struct Node* loadBooks(struct Node *root)
{
    FILE *fp = fopen("books.txt", "r");

    if(fp == NULL)
        return root;

    while(1)
    {
        struct Node *newNode = malloc(sizeof(struct Node));

        if(fscanf(fp, "%d|%49[^|]|%49[^|]|%d|%d|%d\n",
                   &newNode->bookId,
                   newNode->title,
                   newNode->author,
                   &newNode->available,
                   &newNode->issueDay,
                   &newNode->dueDay) != 6)
        {
            free(newNode);
            break;
        }

        newNode->left = NULL;
        newNode->right = NULL;

        root = insert(root, newNode);
    }

    fclose(fp);
    return root;
}
int main()
{
    struct Node *root = NULL;
    root = loadBooks(root);
    int choice;

    while(1)
    {
        printf("\n\n===== LIBRARY MANAGEMENT SYSTEM =====");
        printf("\n1. Add Book");
        printf("\n2. Search Book");
        printf("\n3. Display Books");
        printf("\n4. Issue Book");
        printf("\n5. Return Book");
        printf("\n6. Delete Book");
        printf("\n7. Exit");
       
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                struct Node *newBook = createNode();
                root = insert(root, newBook);
                printf("\nBook added successfully!\n");
                break;
            }

            case 2:
            {
                int id;

                printf("\nEnter Book ID to search: ");
                scanf("%d", &id);

                struct Node *book = search(root, id);

                if(book != NULL)
                {
                    printf("\nBook Found!");
                    printf("\nBook ID: %d", book->bookId);
                    printf("\nTitle: %s", book->title);
                    printf("\nAuthor: %s", book->author);

                    if(book->available == 1)
                       printf("\nStatus: Available\n");
                    else
                       printf("\nStatus: Issued\n"); 

                }
                else
                {
                    printf("\nBook not found!\n");
                }

                break;
                
            }
            
            case 3:
                inorder(root);
                break;
            
            case 4:
            {
                int id;

                printf("\nEnter Book ID to issue: ");
                scanf("%d", &id);

                issueBook(root, id);

                break;
            }

            case 5:
            {
                int id;

                printf("\nEnter Book ID to return: ");
                scanf("%d", &id);

                returnBook(root, id);

                break;
            }

            case 6:
            {
                int id;

                printf("\nEnter Book ID to delete: ");
                scanf("%d", &id);

                root = deleteBook(root, id);

                break;
            }

            case 7:
            {
                FILE *fp = fopen("books.txt", "w");
                if(fp != NULL)
                {
                    saveBooks(root,fp);
                    fclose(fp);
                }
                printf("\nThank you!\n");
                return 0;
            }
                
            default:
                printf("\nInvalid choice!\n");
        }
    }
}
