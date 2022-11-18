#include<stdio.h>
#define Max 4
int stack[Max],item;
int ch,top=-1,count=0,status=0;
void push(int stack[],int item)
{
    if(top==(Max-1))
    {
        printf("\n\n stack is overflow");
    }
    else{
        stack[++top]=item;
        status++;
    }
}
int pop(int stack[])
{
    int ret;
    if(top==-1)
    {
        printf("\n\n stack is underflow");
    }
    else{
        ret=stack[top--];
        status--;
        printf("\n popped element is %d",ret);
    }
    return ret;
}
void pallindrome(int stack[])
{
    int i,temp;
    temp=status;
    for(i=0;i<temp;i++)
    {
        if(stack[i]==pop(stack))
        count++;

    }
    if(temp==count)
    {
        printf("\n stack contents are pallindrome");
    }else{
        printf("syack content are not pallindrome");
    }
}
void display(int syack[])
{
    int i;
    printf("\n the stack content are :");
    if (top==-1)
    {
        printf("\n stack is empty");
    }else{
        for(i=top;i>=0;i--)
        {
            printf("\n %d",stack[i]);
            printf("\n");
        }
    }
}
void main()
{
    do{
        printf("\n------MAIN MENU------\n");
        printf("\n 1.PUSH(insert) in stack");
        printf("\n 2. POP(delete) in stack");
        printf("\n 3. pallindrome check using stack");
        printf("\n 4. Exit");
        printf("\n enter your choice");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\n enter a element to be pushed");
                    scanf("%d",& item);
                    push(stack,item);
                    display(stack);
                    break;
            case 2: item=pop(stack);
                    display(stack);
                    break;
            case 3: pallindrome(stack);
                    break;
            case 4: exit(0);
            default: printf("end of execution");
        }
    }while(ch!=4);
}
