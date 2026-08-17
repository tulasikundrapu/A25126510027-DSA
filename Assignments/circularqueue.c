#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5
int queue[MAX_SIZE];
int front=-1;
int rear=-1;
int isfull()
{
    return ((rear+1)% MAX_SIZE==front);        
}
int isempty()
{
    return (front==-1);
}
void enqueue(int value)
{
    if (isfull())
    {
        printf("Queue is overflow\n");
        return;
    }
    if(isempty())
    {
        front = 0;
    }
    rear=(rear+1)%MAX_SIZE;
    queue[rear]=value;
    printf("Enqueued:%d\n", value);
}
int dequeue()
{
    int value;
    if (isempty())
    {
        printf("Queue is Underflow\n");
        return -1;
    }
    value=queue[front];
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        front=(front+1)%MAX_SIZE;
    }
    printf("dequeud:%d", value);
    return value;
}
void display()
{
    int i;
    if(isempty())
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue Contents:");
    i=front;
    while(1)
    {
        printf("%d  ",queue[i]);
        if(i==rear)
            break;
        i=(i+1)%MAX_SIZE;
    }
    printf("\n");
}
int main()
{
    int choice,value;
    while (1)
    {
        printf("\nMenu\n");
        printf("1.Insertion(Enqueue)\n");
        printf("2.Deletion(Dequeue)\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d",&value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}