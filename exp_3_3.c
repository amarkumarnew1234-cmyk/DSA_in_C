//Infix to Postfix Conversion
#include<stdio.h>
#include<ctype.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c){ stack[++top] = c; }
char pop(){ return stack[top--]; }
int precedence(char c){
    if(c=='+'||c=='-') return 1;
    if(c=='*'||c=='/') return 2;
    return 0;
}

int main(){
    char infix[100], postfix[100];
    int k=0;
    printf("Enter infix expression: ");
    scanf("%s", infix);
    
    for(int i=0; infix[i]!='\0'; i++){
        if(isalnum(infix[i]))
            postfix[k++] = infix[i];
        else if(infix[i]=='(')
            push(infix[i]);
        else if(infix[i]==')'){
            while(stack[top]!='(')
                postfix[k++] = pop();
            pop();
        }
        else{
            while(top!=-1 && precedence(stack[top])>=precedence(infix[i]))
                postfix[k++] = pop();
            push(infix[i]);
        }
    }
    while(top!=-1)
        postfix[k++] = pop();
    postfix[k]='\0';
    
    printf("Postfix: %s", postfix);
    return 0;
}
