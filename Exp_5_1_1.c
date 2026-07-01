//Implementing binary tree using array
#include<stdio.h>
#define SIZE 100
int tree[SIZE];
void insert(int value,int index){
    if(index>=SIZE){
        printf("overflow\n");
        return;
    }
    tree[index]=value;
}
void display(){
    int i;
    for(i=0;i<SIZE;i++){
        if(tree[i]!=0){
            printf("%d ",tree[i]);
        }
    }
}
int main(){
    int n,i,value;
    for(i=0;i<SIZE;i++){
        tree[i]=0;
    }
    printf("enter no.of nodes:");
    scanf("%d",&n);
    printf("enter values:");
    for(i=0;i<n;i++){
        scanf("%d",&value);
        insert(value,i);
    }
    display();
    return 0;
}