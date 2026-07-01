//implementing binary tree usng linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* create(int value){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
struct node* insertLevel(struct node* root,int value){
    struct node* newnode=create(value);
    if(root==NULL){
        return newnode;
    }
    struct node* queue[100];
    int front=0,rear=0;
    queue[rear++]=root;
    while(front<rear){
        struct node* temp=queue[front++];
        if(temp->left==NULL){
            temp->left=newnode;
            return root;
        }else{
            queue[rear++]=temp->left;
        }
        if(temp->right==NULL){
            temp->right=newnode;
            return root;
        }else{
            queue[rear++]=temp->right;
        }
    }
    return root;
}
void preorder(struct node* root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
int main(){
    struct node* root=NULL;
    int n,i,value;
    printf("enter no.of nodes:");
    scanf("%d",&n);
    printf("enter values:");
    for(i=0;i<n;i++){
        scanf("%d",&value);
        root=insertLevel(root,value);
    }
    preorder(root);
    return 0;
}