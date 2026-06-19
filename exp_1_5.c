//find the product of two matrices using pointers.
#include <stdio.h>
int main() {
    int r1,c1,r2,c2,i,j,k;
    int a[10][10],b[10][10],c[10][10];
    int *p1,*p2,*p3;
    printf("Enter rows of first matrix:");
    scanf("%d",&r1);
    printf("Enter columns of first matrix:");
    scanf("%d",&c1);
    printf("Enter rows of second matrix:");
    scanf("%d",&r2);
    printf("Enter columns of second matrix:");
    scanf("%d",&c2);
    if(c1!=r2){
        printf("Matrix multiplication not possible");
        return 0;
    }
    printf("Enter elements of first matrix:");
    for(i=0;i<r1;i++)
        for(j=0;j<c1;j++)
            scanf("%d",&a[i][j]);
    printf("Enter elements of second matrix:");
    for(i=0;i<r2;i++)
        for(j=0;j<c2;j++)
            scanf("%d",&b[i][j]);
    for(i=0;i<r1;i++){
        for(j=0;j<c2;j++){
            *(c[i]+j)=0;
            for(k=0;k<c1;k++){
                p1=&a[i][k];
                p2=&b[k][j];
                p3=&c[i][j];
                *p3=*p3+(*p1)*(*p2);
            }
        }
    }
    printf("Product matrix:");
    for(i=0;i<r1;i++)
        for(j=0;j<c2;j++)
            printf("%d ",c[i][j]);
}


