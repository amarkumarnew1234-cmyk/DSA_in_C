#include<stdio.h>
int heap[100],n=0;
void insert(int val){
    n++;
    int i=n;
    heap[i]=val;
    while(i>1&&heap[i]>heap[i/2]){
        int temp=heap[i];
        heap[i]=heap[i/2];
        heap[i/2]=temp;
        i=i/2;
    }
}
void delete(){
    if(n==0){
        printf("Heap empty");
        return;
    }
    printf("Deleted:%d\n",heap[1]);
    heap[1]=heap[n];
    n--;
    int i=1;
    while(2*i<=n){
        int largest=i,l=2*i,r=2*i+1;
        if(l<=n&&heap[l]>heap[largest])largest=l;
        if(r<=n&&heap[r]>heap[largest])largest=r;
        if(largest!=i){
            int temp=heap[i];
            heap[i]=heap[largest];
            heap[largest]=temp;
            i=largest;
        }else break;
    }
}
void display(){
    int i;
    printf("Heap:");
    for(i=1;i<=n;i++)printf("%d ",heap[i]);
    printf("\n");
}
int main(){
    int ch,val;
    while(1){
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("Enter value:");scanf("%d",&val);insert(val);break;
            case 2:delete();break;
            case 3:display();break;
            case 4:return 0;
        }
    }
}