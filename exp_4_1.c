//1. To implement queue using array.
#include<stdio.h>
#define MAX 5
int queue[MAX], front=-1, rear=-1;

void insert(int val){
 if(rear==MAX-1) printf("Overflow\n");
 else{
  if(front==-1) front=0;
  queue[++rear]=val;
 }
}

void delete(){
 if(front==-1 || front>rear) printf("Underflow\n");
 else printf("Deleted: %d\n", queue[front++]);
}

void display(){
 if(front==-1) printf("Empty\n");
 else{
  for(int i=front;i<=rear;i++) printf("%d ",queue[i]);
 }
}

int main(){
 int ch,val;
 while(1){
  printf("\n1.Insert 2.Delete 3.Display 4.Exit\n");
  scanf("%d",&ch);
  switch(ch){
   case 1: scanf("%d",&val); insert(val); break;
   case 2: delete(); break;
   case 3: display(); break;
   case 4: return 0;
  }
 }
}

