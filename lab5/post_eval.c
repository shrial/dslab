#include<stdio.h>
int top=-1;
void push(int arr[],int val){
    arr[++top]=val;
}
int pop(int arr[]){
    if(top!=-1){
    int popped=arr[top--];
    return popped;
    }
}
int eval(char str[50]){
    int var[50];
    for(int i=0;str[i]!='\0';i++){
       if(str[i]=='/'||str[i]=='*'||str[i]=='%'||str[i]=='+'||str[i]=='-') {
        int b=pop(var);
        int a=pop(var);
        if(str[i]=='+'){
            push(var,a+b);
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
    return var[0];
}
void main(){
char str[100];
printf("enter a postfix expression");
gets(str);
printf("evaluation of the postfix form is: \n");
int e=eval(str);
printf("%d",e);

}
