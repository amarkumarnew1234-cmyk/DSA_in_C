// Create an array 'al' with 'n' elements. 
//Insert an element in ith position of 'al' and also delete an element from jth position of 'al'.
#include <stdio.h>
int main() {
    int n,a1[100],i,j,pos,val;
    printf("no. of elements:");
    scanf("%d",&n);
    printf("enter %d elements separated by space:", n);
    for(i=0;i<n;i++)
        scanf("%d",&a1[i]);
    printf("position to insert:");
    scanf("%d",&pos);
    printf("value to insert:");
    scanf("%d",&val);
    for(i=n;i>pos-1;i--)
        a1[i]=a1[i-1];
    a1[pos-1]=val;
    n++;
    printf("array after insertion:");
    for(i=0;i<n;i++)
        printf("%d ",a1[i]);
    printf("\nposition to delete:");
    scanf("%d",&j);
    for(i=j-1;i<n-1;i++)
        a1[i]=a1[i+1];
    n--;
    printf("array after deletion:");
    for(i=0;i<n;i++)
        printf("%d ",a1[i]);
}
