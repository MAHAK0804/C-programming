#include<stdio.h>
int main()
{
   int i,j,p,s,n,a[20];
   printf("enter the no. of elements to be sorted\n");
   scanf("%d",&n);
   printf("enter the value\n");  
   for(i=0;i<n;i++)
   {
      scanf("%d",&a[i]);
   }
   printf("list before sorting\n");
    for(i=0;i<n;i++)
   {
      printf("a[%d]=%d\n",i,a[i]);
   }
   for(i=0;i<n-1;i++)
   {
      p=i;
      for(j=i+1;j<n;j++)
      {
         if(a[p]>a[j])
         {
            p=j;
         }
      }
      if(p!=i)
      {
         s=a[i];
         a[i]=a[p];
         a[p]=s;
      }
   }
       printf("list after sorting\n");
    for(i=0;i<n;i++)
   {
      printf("a[%d]=%d\n",i,a[i]);
   }
   
}