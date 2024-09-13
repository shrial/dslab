//int s==1 and check with the output of or result
#include<stdio.h>
#include<string.h>
int top=-1,top1=-1,ass=0;
char op[50];
char var[50];
void push(char arr[],char val){
    arr[++top]=val;
}
char pop(char arr[]){
    if(top!=-1){
    char popped=arr[top--];
    return popped;
    }
}
int prec(char s)
{
        if(s==('^')){
            ass=1;
           return 4;

           }
        if(s=='/'||s=='*'){
            ass=0;
           return 3;
           }
        if(s=='+'||s=='-'){
            ass=0;
           return 2;
           }
        if(s=='('){
            return 1;
           }
}
void postfix(char str[]){

    int pre1=0;
     for(int i=0;str[i]!='\0';i++){

         if(str[i]=='('){
                push(op,str[i]);
            }
        else if(str[i]=='/'||str[i]=='*'||str[i]=='+'||str[i]=='-'||str[i]=='^'){
                int pre=prec(str[i]);
            if(pre>pre1){
                push(op,str[i]);
                pre1=pre;
            }

            else if(pre==pre1){
                    if(ass==0){


                    char popped=pop(op);
                    var[++top1]=popped;
                push(op,str[i]);}
                else{
                    push(op,str[i]);
                }
                pre1=pre;
            }
            else if(pre<pre1){
                while(prec(op[top])>pre){
                    char popped=pop(op);
                    var[++top1]=popped;
                }
                push(op,str[i]);
                pre1=pre;
            }
        }
        else if(str[i]==')'){
            while((op[top])!='('){
                    char popped=pop(op);
                    var[++top1]=popped;
                  }
                  pop(op);
                  if(top!=-1)
                  pre1=prec(op[top]);
        }
        else{
            var[++top1]=str[i];
        }
     }
     while(top!=-1){
        char popped=pop(op);
        var[++top1]=popped;
     }
     for(int i=0;str[i]!='\0';i++){
printf("%c",var[i]);}
    }

int main(){
char str[100];
printf("enter an expression");
gets(str);
printf("expression in postfix form is: \n");
postfix(str);

}
