//Find the sum of rows and columns of matrix of given order(row * column)
#include <stdio.h>
int main() {
    int r,c,i,j,a[10][10],row_sum,col_sum;
    printf("Enter rows:");
    scanf("%d",&r);
    printf("Enter columns:");
    scanf("%d",&c);
    printf("Enter matrix elements:");
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            scanf("%d",&a[i][j]);
    for(i=0;i<r;i++){
        row_sum=0;
        for(j=0;j<c;j++)
            row_sum=row_sum+a[i][j];
        printf("Sum of row %d:",i+1);
        printf("%d",row_sum);
    }
    for(j=0;j<c;j++){
        col_sum=0;
        for(i=0;i<r;i++)
            col_sum=col_sum+a[i][j];
        printf("Sum of column %d:",j+1);
        printf("%d",col_sum);
    }
}

