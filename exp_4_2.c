//2. To implement queue using linked list.
#include<stdio.h>
#include<stdlib.h>
struct node{int data; struct node* next;};
struct node *front=NULL,*rear=NULL;

void insert(int val){
 struct node* temp=(struct node*)malloc(sizeof(struct node));
 temp->data=val; temp->next=NULL;
 if(rear==NULL) front=rear=temp;
 else{ rear->next=temp; rear=temp; }
}

void delete(){
 if(front==NULL) printf("Underflow\n");
 else{
  struct node* temp=front;
  printf("Deleted: %d\n",temp->data);
  front=front->next;
  free(temp);
 }
}

void display(){
 struct node* temp=front;
 while(temp!=NULL){
  printf("%d ",temp->data);
  temp=temp->next;
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
