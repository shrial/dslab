//its workinggggggggggggggggggggggggggggggggggggggggggggggg yayyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy
#include<stdio.h>
int top=-1,ass=0;
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
    int len=strlen(str);
    for(int i=0;i<(len/2);i++){
        char temp=str[i];
        str[i]=str[len-1-i];
        str[len-1-i]=temp;
    }

    for(int i=0;str[i]!='\0';i++){
       if(str[i]=='/'||str[i]=='*'||str[i]=='%'||str[i]=='+'||str[i]=='-') {
        int b=pop(var);
        int a=pop(var);
        if(str[i]=='+'){
            push(var,a+b);
        }
        else if(str[i]=='-'){
            push(var,b-a);
        }
        else if(str[i]=='/'){
            push(var,b/a);
        }
        else if(str[i]=='*'){
            push(var,a*b);
        }
        else if(str[i]=='%'){
            push(var,a%b);
        }
        else if(str[i]=='^'){
            push(var,b^a);
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
printf("enter a prefix expression");
gets(str);
printf("evaluation of the prefix form is: \n");
int e=eval(str);
printf("%d",e);

}

