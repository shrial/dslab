#include<stdio.h>
#include<string.h>
void push(char arr[],char val){
    arr[++top]=val;
}
char* pop(char arr[]){
    if(top!=-1){
    char popped=arr[top--];
    return popped;
    }
}
void convert(char str[]){
char con[50][50];
    for(int i=0;str[i]!='\0';i++){
       if(str[i]=='/'||str[i]=='*'||str[i]=='%'||str[i]=='+'||str[i]=='-') {
        char b=pop(var);
        char a=pop(var);
        if(str[i]=='+'){
            push(var,);
        }
        else if(str[i]=='-'){
            push(var,a-b);
        }
        else if(str[i]=='/'){
            push(var,a/b);
        }
        else if(str[i]=='*'){
            push(var,a*b);
        }
        else if(str[i]=='%'){
            push(var,a%b);
        }
        else if(str[i]=='^'){
            push(var,a^b);
        }
       }
       else{
        push(var,((int)str[i])-48);
       }
}

int main(){
    char str[100];
printf("enter a postfix expression");
gets(str);
printf("postfix to infix form is: \n");
}
