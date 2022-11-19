#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head;
//counting number of elements in the list
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
//deleting a node from list depending upon the data in the node
int delnodedata(int num)
{
    struct node *prev_ptr,*cur_ptr;
    cur_ptr=head;
    while(cur_ptr!=NULL)
    {
        if(cur_ptr==head)
        {
            if(cur_ptr==head)
            {
                head=cur_ptr->next;
                free(cur_ptr);
                return 0;
            }
            else{
                prev_ptr->next =cur_ptr->next;
                free(cur_ptr);
                return 0;
            }
        }
        else{
            prev_ptr=cur_ptr;
            cur_ptr=cur_ptr->next;
        }
    }
        printf("\n Element %d is not found in the list",num);
        return 1;
}
//deleting a node from list depending upon the location in the list
int delnodeloc(int loc)
{
    struct node *prev_ptr, *cur_ptr;
    int i;
    cur_ptr=head;
    if(loc>(length())||loc<=0)
    {
        printf("\n deletion of node at given location is not possible\n");
    }
    else{
        //if the location is starting of the list
        if(loc==1)
        {
            head=cur_ptr->next;
            free(cur_ptr);
            return 0;
        }
        else{
            for(i=0;i<loc;i++)
            {
                prev_ptr=cur_ptr;
                cur_ptr=cur_ptr->next;
            }
            prev_ptr->next=cur_ptr->next;
            free(cur_ptr);
        }
    }
    return 1;
}
//adding a node at the end of the list
void addend(int num)
{
    struct node *temp1, *temp2;
    temp1=(struct node*)malloc(sizeof(struct node));
    temp1->data=num;
    //copying the head location into another node.
    temp2=head;
    if(head==NULL)
    {
        //if list is empty we create first node
        head=temp1;
        head->next=NULL;
    } 
    else{
        //traverse down to end of the list.
        while(temp2->next!=NULL)
        {
            temp2=temp2->next;
            //append at the end of the list.
            temp1->next=NULL;
            temp2->next=temp1;
        }
    }
}
//adding a node at the beginning of the list
void addbeg(int num)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=num;
    if(head==NULL)
    {
        //list is empty 
        //head=temp;
        temp->next=NULL;
        head= temp;
    }
    else{
        temp->next=head;
        head=temp;
    }
}
//adding a new node at specified position.
void addat(int num,int loc)
{
    int i;
    struct node *temp,*prev_ptr,*cur_ptr;
    cur_ptr=head;
    if(loc>(length()+1)||loc<=0)
    {
        printf("\n insertion at given location is not poosible\n");
    }
    else{
        //if the location is starting of the list
        if(loc==1)
        {
            addbeg(num);
        }
        else{
            for(i=1;i<loc;i++)
            {
                prev_ptr=cur_ptr;
                cur_ptr=cur_ptr->next;
            }
            temp=(struct node*)malloc(sizeof(struct node));
            temp->data=num;
            prev_ptr->next=temp;
            temp->next=cur_ptr;
        }
    }
}
//displaying list contents
void display()
{
    struct node *cur_ptr;
    cur_ptr=head;
    if(cur_ptr==NULL)
    {
        printf("\n list is empty");
    }
    else{
        printf("\n elements in the list:");
        //traverse the entire linked list
        while(cur_ptr!=NULL)
        {
            printf("-> %d",cur_ptr->data);
            cur_ptr=cur_ptr->next;
        }
        printf("\n");
    }
}
//reversesing a linked list
void reverse()
{
    struct node *prev_ptr,*cur_ptr,*temp;
    cur_ptr=head;
    prev_ptr=NULL;
    while(cur_ptr!=NULL)
    {
        temp=prev_ptr;
        prev_ptr=cur_ptr;
        cur_ptr=cur_ptr->next;
        prev_ptr->next=temp;
    }
    head=prev_ptr;
}
int main(int argc, char*argv[])
{
    int i=0;
    //set head as null
    head=NULL;
    while(1)
    {
        printf("\n####################################\n");
        printf("MANI MENU\n");
        printf("######################################\n");
        printf("/n Insert a number /n"); 
        printf(" 1. At the Beginning/n");       
        printf("2. At the End/n");
        printf("3. At a Particular Location in the List/n ");     
        printf(" 4. Print the elements in the list/n");       
        printf(" 5. Print number of elements in the list /n");      
        printf("6. Reverse the linked list /n ");       
        printf("7. Delete a node in the list by value /n");         
        printf("  8. Delete a node based on location/n");      
        printf("  9. delete a last /n");
        printf("no. Exit /n ");               
        printf(" Choose Option:");        
        scanf("%d",&i);
        switch(i)
        {
            case 1: {
                    int num;
                    printf("/n Enter a number to insert in the list:");
                    scanf("%d",& num);
                    addbeg(num);
                    display();
                    break;
                    }
            case 2: {
                      int num;
                    printf("/n Enter the number to insert: ");
                    scanf("%d",&num);
                    addend(num);
                    display();
                    break;
                    }
            case 3: {
                      int num, loc;
                    printf("/n Enter the number to insert:");
                    scanf("%d",&num);
                    printf("/n enter the location number in list at which the number is inserted:");
                    scanf("%d",&loc);
                    addat(num, loc);
                    display();
                    break;
                    }
            case 4: {
                     display();
                    break;
                    }
            case 5: {
                    display();
                     printf("/n total number of nodes in the list: %d",length());
                     break;
                   }
            case 6:{
                    reverse();
                    display();
                    break;
                   }
            case 7:{
                     int num;
                    printf("\n Enter the number to be deleted from list:");
                    scanf("%d",&num);
                    delnodedata(num);
                    display();
                    break;
                  }
            case 8: {
                    int num;
                    printf("\n Enter the location of the node to be deleted from list");
                    scanf("%d",&num);
                    delnodeloc(num);
                    display();
                    break;
                    }
            case 9: {
                    struct node *temp1,*temp2;
                    if(head->next== NULL)
                    {
                        head=NULL;
                    }
                    else{
                        temp1=head;
                        temp2= head->next;
                        while(temp2->next!=NULL)
                        {
                            temp1=temp2;
                            temp2=temp2->next;
                        }
                        temp1->next=NULL;
                        free(temp2);
                    }
                    display();
                    break;
                   }
            default: printf("\n Wrong option choosen");
        }

    }
}
