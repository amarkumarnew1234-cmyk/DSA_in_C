//4. To implement circular queue.
#include<stdio.h>
#define MAX 5
int cq[MAX], front=-1,rear=-1;

void insert(int val){
 if((rear+1)%MAX==front) printf("Full\n");
 else{
  if(front==-1) front=0;
  rear=(rear+1)%MAX;
  cq[rear]=val;
 }
}

void delete(){
 if(front==-1) printf("Empty\n");
 else{
  printf("Deleted: %d\n",cq[front]);
  if(front==rear) front=rear=-1;
  else front=(front+1)%MAX;
 }
}

void display(){
 int i=front;
 while(1){
  printf("%d ",cq[i]);
  if(i==rear) break;
  i=(i+1)%MAX;
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
