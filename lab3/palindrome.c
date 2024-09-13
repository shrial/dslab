#include<stdio.h>
#include<string.h>
int top=-1,flag=1;
void push(char arr[],char value){
    arr[++top]= value;
}
char pop(char arr[]){
    char popped = arr[top--];
    return popped;
}
void check(char str[],char st[]){
for(int i=0;str[i]!='\0';i++){
    push(st,str[i]);
}

for(int i=0;i<=top;i++){
    char popped=pop(st);
    if(popped!=st[i]){
        flag=0;
        break;
    }
}}
void main(){
    int popped;
char str[100],st[100];
printf("enter a string");
gets(str);
check(str,st);
if (flag==0){
    printf("string is not a palindrome");
}
else{
    printf("string is a palindrome");
}
}

