#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node 
{
    char song[1000];
    struct Node *next;
};
struct Node *head = NULL;
void insertSong(char song[], int pos) 
{
    struct Node *newNode, *temp;
    int i;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->song, song);

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    temp = head;

    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}
void deleteSong(int pos) {
    struct Node *temp, *del;
    int i;

    if (head == NULL) {
        printf("Playlist is empty\n");
        return;
    }

    if (pos == 1) {
        del = head;
        head = head->next;
        free(del);
        return;
    }

    temp = head;

    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position\n");
        return;
    }

    del = temp->next;
    temp->next = del->next;
    free(del);
}
void display() {
    struct Node *temp = head;
    int pos = 1;

    if (head == NULL) {
        printf("Playlist is empty\n");
        return;
    }

    while (temp != NULL) {
        printf("%d. %s\n", pos, temp->song);
        temp = temp->next;
        pos++;
    }
}

int main() {
    int choice, position;
    char song[1000];
     while (1) 
     {
        printf("\n--- MUSIC PLAYLIST ---\n");
        printf("1.Insert Song\n");
        printf("2.Delete Song\n");
        printf("3.Display Playlist\n");
        printf("4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1: printf("Enter song name: ");
                    scanf(" %[^\n]", song);
                    printf("Enter song position: ");
                    scanf("%d", &position);
                    insertSong(song, position);
                    break;
             case 2:printf("Enter position to delete: ");
                    scanf("%d", &position);
                    deleteSong(position);
                    break;
            case 3:display();
                   break;
            case 4:printf("Exit\n");
                   return 0;
            default:printf("Invalid choice\n");
        }
    }

    return 0;
}
