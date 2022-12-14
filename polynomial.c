#include<stdio.h>
#include<stdlib.h>
struct poly
{
    float coff;
    int exp;
};
//delaration of polynomials
struct poly a[50],b[50],c[50],d[50];
int main()
{
    int i,deg1,deg2,k=0,l=0,m=0;
    printf("Enter the highest degree of poly1:");
    scanf("%d",&deg1);
    //taking polynoimal terms from the user
    for(i=0;i<=deg1;i++)
    {
        //entering values in cofficent of the polynomials terms
        printf("\n Enter the coff of x^%d:",i);
        scanf("%f",&a[i].coff);
        //entering values in exponent of the polyomial terms
        a[k++].exp= i;
    }
    //taking second polynomial from the user
    printf("\n Enter the highest degree of poly2:");
    scanf("%d",&deg2);
    for(i=0;i<=deg2;i++)
    {
        printf("\nEnter the coff of x^%d",i);
        scanf("%f",&b[i].coff);
        b[l++].exp=i;
    }
    //printing first polynomial
    printf("\nExpression 1=%f",a[0].coff);
    for(i=0;i<=deg1;i++)
    {
        printf("+%fx^%d",a[i].coff,a[i].exp);
    }
    //printing second polynomial
    printf("\nExpression 2=%f",b[0].coff);
    for(i=0;i<=deg2;i++)
    {
        printf("+%fx^%d",b[i].coff,b[i].exp);
    }
    //adding the polynomial
    if(deg1>deg2)
    {
        for(i=0;i<=deg2;i++)
        {
            c[m].coff=a[i].coff+b[i].coff;
            c[m].exp=a[i].exp;
            m++;
        }
        for(i=deg2+1;i<=deg1;i++)
        {
            c[m].coff=a[i].coff;
            c[m].exp=a[i].exp;
            m++;
        }
    }else{
         for(i=0;i<=deg1;i++)
        {
            c[m].coff=a[i].coff+b[i].coff;
            c[m].exp=b[i].exp;
            m++;
        }
        for(i=deg1+1;i<=deg2;i++)
        {
            c[m].coff=b[i].coff;
            c[m].exp=b[i].exp;
            m++;
        }
    }
    //printing sum of two polynomial
    printf("\nExpression after sum=%f",c[0].coff);
    for(i=0;i<=m;i++)
    {
        printf("+%fx^%d",c[i].coff,c[i].exp);
    }
}