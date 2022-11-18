#include<stdio.h>
int main()
{
   int i,j,p,s,n,a[20],c,d,t;
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
      for(c=1;c<=n-1;c++)
      {
         d=c;
        while(d>0 && a[d]<a[d-1])
        {
           t=a[d];
           a[d]=a[d-1];
           a[d-1]=t;
           d--;
        }
      }
   }
       printf("list after sorting\n");
    for(i=0;i<n;i++)
   {
      printf("a[%d]=%d\n",i,a[i]);
   }
   
}






#include<stdio.h>
int main()
{
   int i,l, h, m,n,k,a[20];
   printf("enter no. of elements\t");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
      scanf("%d",&a[i]);
   }
   printf("list of array is\n");
    for(i=0;i<n;i++)
   {
      printf("a[%d]=%d\n",i,a[i]);
   }
   printf("enter the number to be searched \t");
   scanf("%d",&k);
   l=0;
   h=n-1;
   m=(l+h)/2;
   while(l<=h)
   {
      if(a[m]<k)
         l=m+1;
          printf("the element at location %d\n",l);
   else
   {
      if(a[m]=k)
      {
         printf("the element at location %d\n",m-1);
         break;
      }
      else
      {
          h=m-1;
      }
         
      
   }

   if(l>h)
   {
      printf("%d notfound in the list",k);
      
   }
}