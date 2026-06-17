//find sum of all array elements using recursion
#include<stdio.h>
int sum(int a[], int n)
{
   if(n==0)
    return 0;
    else
    return a[n-1] + sum(a,n-1);
}
int main()
{
    int a[50],n,i;
    printf("Enter number of elements:");
    scanf("%d",&n);
    printf("Enter the elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("%d",sum(a,n));
    return 0;
}