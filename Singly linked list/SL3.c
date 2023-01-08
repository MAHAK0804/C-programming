#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head;
void addnode(int num)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=num;
    if(head==NULL)
    {
        temp->next=NULL;
        head=temp;
    }else
    {
        temp->next=head;
        head=temp;
    }
}
int length()
{
    struct node *cur_ptr;
    int count=0;
    cur_ptr=head;
    while(cur_ptr!=NULL)
    {
        cur_ptr=cur_ptr->next;
        count++;
    }
    return(count);
}
void display()
{
    struct node*cur_ptr;
    cur_ptr=head;
    if(cur_ptr==NULL)
    {
        printf("\n list is empty");
    }else{
    while(cur_ptr!=NULL)
    {
        printf("%d",cur_ptr->data);
        cur_ptr=cur_ptr->next;
    }
    printf("\n");
    }
}
int main()
{
    head=NULL;
    int num,i;
    for(i=0;i<5;i++)
    {
        scanf("%d",&num);
        addnode(num);
    }
    printf("elements in list\n");
    display();
    printf("number of elements in list= %d",length());
}