//6. To implement queue using stacks.
#include<stdio.h>
#define MAX 5

int s1[MAX], s2[MAX];
int top1=-1, top2=-1;

void push1(int val){ s1[++top1]=val; }
int pop1(){ return s1[top1--]; }

void push2(int val){ s2[++top2]=val; }
int pop2(){ return s2[top2--]; }

void enqueue(int val){
    push1(val);
}

void dequeue(){
    if(top1==-1 && top2==-1){
        printf("Queue Empty\n");
        return;
    }

    if(top2==-1){
        while(top1!=-1){
            push2(pop1());
        }
    }

    printf("Dequeued: %d\n", pop2());
}

int main(){
    int ch,val;
    while(1){
        printf("\n1.Enqueue 2.Dequeue 3.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: scanf("%d",&val); enqueue(val); break;
            case 2: dequeue(); break;
            case 3: return 0;
        }
    }
}
