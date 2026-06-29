//3. To check palindrome.
#include<stdio.h>
#include<string.h>

int main(){
 char str[50];
 int flag=1;
 scanf("%s",str);
 int n=strlen(str);
 for(int i=0;i<n/2;i++){
  if(str[i]!=str[n-i-1]){ flag=0; break; }
 }
 if(flag) printf("Palindrome");
 else printf("Not Palindrome");
 return 0;
}
