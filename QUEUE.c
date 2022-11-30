#include<stdio.h>
#include<stdlib.h>
#define Max 10
int QUEUE[Max],front=-1,rear=-1;
/*function : insert_in_Q(),to push an item into queue*/
void insertinQ(int QUEUE[],int ele)
{
    if (rear==-1)
    {
        front=rear=0;
        QUEUE[rear]=ele;
    }
    else if(rear==Max-1)
    {
        printf("\n QUEUE is full. \n");
        return 0;
    }else{
        rear++;
        QUEUE[rear]=ele;
    }
    printf("\n Item inserted..");
}
/* function: display_Q(),to display queue elements*/
void display_Q(int QUEUE[])
{
    int i;
    if(rear==-1)
    {
        printf("\n QUEUE is empty");
        return 0;
    }
    for(i=front;i<=rear;i++)
    {
        printf("%d",QUEUE[i]);
    }
}
/* function: remove_from_Q(),to remove(pop)an item from queue*/
void remove_from_Q(int queue[])
{
    int ele;
    if(front==-1)
    {
        printf("QUEUE is empty");
        return 0;
    }else if(front==rear)
    {
        ele=QUEUE[front];
        front=rear=-1;
    }else{
        ele=QUEUE[front];
        front++;
    }
    printf("\n Item removed:%d",ele);
}
int main()
{
    int ele,choice;
    while(1)
    {
        printf("\nQUEUE elements are:");
    display_Q(QUEUE);
    printf("\n\nEnter choice\n 1.Insert\n2.Display\n3.Remove\n0.Exit");
    scanf("%d",&choice);
    switch(choice)
    {
        case 0: exit(0);
                break;
        case 1: printf("Enter an element to insert:");
                scanf("%d",&ele);
                insertinQ(QUEUE,ele);
                break;
        case 2: display_Q(QUEUE);
                break;
        case 3: remove_from_Q(QUEUE);
                break;
        default: printf("\nInvalid choice\n");
                    break;
    }
    }
    return 0;
}