#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct  node*second;
}*first;

//adding a node at the beginning of the list
void addnode(int num)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    if(first==NULL)
    {
       newnode->second=NULL;
        first=newnode;
    }else{
       newnode->second=first;
        first=newnode;
    }
}

//display list
void display()
{
    struct node *cur_ptr;
    cur_ptr=first;
    if(cur_ptr==NULL)
    {
        printf("list is empty");
    }else
    {
        while(cur_ptr!=NULL)
        {
            printf("%d",cur_ptr->data);
            cur_ptr=cur_ptr->second;
        }
        printf("\n");
    }
}

int main()
{
    first==NULL;
    int num,i;
    printf("enter elements in list\n");
    for(i=0;i<5;i++)
    {
         scanf("%d",&num);
         addnode(num);
    }
    printf("elements in list-->\n");
    display();
}