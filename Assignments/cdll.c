#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
 {
    int passengerId;
    char name[50];
    struct Node *next;
    struct Node *prev;
};
struct Node *head = NULL;
void insert(int id, char name[], int position)
 {
    struct Node *newNode, *temp;
    newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->passengerId = id;
    strcpy(newNode->name, name);
    if (head == NULL) {
        if(position != 1) {
            printf("Invalid position\n");
            free(newNode);
            return;
        }

        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;

        printf("Passenger inserted\n");
        return;
    }
    if (position == 1)
    {
        struct Node *last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
        head = newNode;
        printf("Passenger inserted\n");
        return;
    }
    temp = head;
    for (int i=1;i<position;i++) 
    {
        temp=temp->next;
        if (temp == head)
        {
            printf("Invalid positionition\n");
            free(newNode);
            return;
        }
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
    printf("Passenger inserted\n");
}
void delete(int position) 
{
    struct Node *temp, *last;
    if (head == NULL)
   {
        printf("List is empty\n");
        return;
    }
    temp=head;
    if(position==1)
    {
        if(head->next==head)
         {
            head=NULL;
            free(temp);
        }
         else
        {
            last=head->prev;
            head=head->next;
            head->prev=last;
            last->next=head;
            free(temp);
        }
        printf("Passenger deleted\n");
        return;
    }
    for (int i=1;i<position;i++) 
    {
        temp=temp->next;
      if(temp==head)
        {
            printf("Invalid position\n");
            return;
        }
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
    printf("Passenger deleted\n");
}
void displayForward()
 {
    struct Node *temp;
    if (head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    temp=head;
    printf("\nForward direction:\n");
    do 
    {
        printf("ID: %d, Name: %s\n",temp->passengerId, temp->name);
        temp=temp->next;
    } while(temp!=head);
}
void displayBackward() {
    struct Node *temp;
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    temp=head->prev;
    printf("\nBackward direction:\n");
    do
    {
        printf("ID: %d, Name: %s\n",temp->passengerId, temp->name);
        temp=temp->prev;
    } while(temp!=head->prev);
}
int main() 
{
    int choice, id, position;
    char name[100];
    while(1) 
    {
        printf("\n--- Railway Reservation System ---\n");
        printf("1. Insert Passenger\n");
        printf("2. Delete Passenger\n");
        printf("3. Display Forward\n");
        printf("4. Display Backward\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:printf("Enter Passenger ID: ");
                   scanf("%d", &id);
                   printf("Enter Passenger Name: ");
                   scanf("%s", name);
                   printf("Enter position: ");
                   scanf("%d", &position);
                   insert(id, name, position);
                   break;
            case 2:printf("Enter position to delete: ");
                   scanf("%d", &position);
                   delete(position);
                   break;
            case 3:displayForward();
                   break;
            case 4:displayBackward();
                   break;
            case 5:printf("Exiting\n");
                   return 0;
            default:printf("Invalid choice\n");
        }
    }
    return 0;
}