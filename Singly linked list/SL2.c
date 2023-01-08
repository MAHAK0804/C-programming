#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head;
void display()
{
    struct node *cur_ptr;
    cur_ptr=head;
    if(cur_ptr==NULL)
    {
        printf("list is empty");
    }else{
        while(cur_ptr!=NULL)
        {
            printf("%d",cur_ptr->data);
            cur_ptr=cur_ptr->next;
        }
        printf("\n");
    }
}
void addnode(int num)
{
    struct node *temp, *ptr;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=num;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }else{
        ptr=head;
        while(ptr->next!=NULL)
        {
             ptr=ptr->next;
        }
        ptr->next=temp;
    }
}
int main()
{
    head==NULL;
    int num,i;
    printf("enter the elements in list\n");
    for(i=0;i<5;i++)
    {
        scanf("%d",&num);
        addnode(num);
    }
    printf("elements in list-->");
    display();
}