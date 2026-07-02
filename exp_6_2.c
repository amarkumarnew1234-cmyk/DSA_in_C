#include<stdio.h>
#define size 10
int hash[size];
void init(){
    int i;
    for(i=0;i<size;i++)hash[i]=-1;
}
void insert(int key){
    int i=key%size;
    while(hash[i]!=-1)i=(i+1)%size;
    hash[i]=key;
}
void search(int key){
    int i=key%size,start=i;
    while(hash[i]!=-1){
        if(hash[i]==key){
            printf("Found at:%d\n",i);
            return;
        }
        i=(i+1)%size;
        if(i==start)break;
    }
    printf("Not found\n");
}
void display(){
    int i;
    printf("Table:\n");
    for(i=0;i<size;i++)printf("%d:%d\n",i,hash[i]);
}
int main(){
    int ch,key;
    init();
    while(1){
        printf("\n1.Insert\n2.Search\n3.Display\n4.Exit\nEnter choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("Enter key:");scanf("%d",&key);insert(key);break;
            case 2:printf("Enter key:");scanf("%d",&key);search(key);break;
            case 3:display();break;
            case 4:return 0;
        }
    }
}