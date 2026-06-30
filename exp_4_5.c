//5. To implement stack using queues.
#include<stdio.h>
#define MAX 5
int q1[MAX], q2[MAX];
int f1=-1,r1=-1,f2=-1,r2=-1;
void enqueue(int q[], int *f, int *r, int val){
    if(*r==MAX-1) return;
    if(*f==-1) *f=0;
    q[++(*r)] = val;
}
int dequeue(int q[], int *f, int *r){
    if(*f==-1) return -1;
    int val=q[*f];
    (*f)++;
    if(*f>*r) *f=*r=-1;
    return val;
}
void push(int val){
    enqueue(q2,&f2,&r2,val);
    while(f1!=-1){
        enqueue(q2,&f2,&r2,dequeue(q1,&f1,&r1));
    }
    for(int i=0;i<=r2;i++){
        q1[i]=q2[i];
    }
   f1=0; r1=r2;
    f2=r2=-1;
}
void pop(){
    if(f1==-1){
        printf("Stack Empty\n");
    } else {
        printf("Popped: %d\n",dequeue(q1,&f1,&r1));
    }
}
int main(){
    int ch,val;
    while(1){
        printf("\n1.Push 2.Pop 3.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: scanf("%d",&val); push(val); break;
            case 2: pop(); break;
            case 3: return 0;
        }
    }
}
