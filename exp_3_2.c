//Reverse String using Stack
#include<stdio.h>
#include<string.h>
#define MAX 100

int top = -1;
char stack[MAX];

void push(char c){
    stack[++top] = c;
}

char pop(){
    return stack[top--];
}

int main(){
    char str[100];
    printf("Enter string: ");
    scanf("%s", str);
    
    int len = strlen(str);
    for(int i=0;i<len;i++)
        push(str[i]);
    
    for(int i=0;i<len;i++)
        str[i] = pop();
    
    printf("Reversed string: %s", str);
    return 0;
}
