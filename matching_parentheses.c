#include <stdio.h>
#include<string.h>
struct st{
char arr[50];
int top;
};
void initialize(struct st *s){
    s->top=-1;
}
_Bool isempty(struct st *s){
    return (s->top==-1);
}
_Bool isfull(struct st *s,int len){
    return (s->top==(len-1));
}
void push(struct st *s,char val){
    s->top++;
    s->arr[s->top]=val;
}
void pop(struct st *s){
    s->top--;
    //return popped;
}
void check(struct st *s,char str[]){
    for(int i=0;str[i]!='\0';i++){
        if(str[i]=='('){
            push(s,str[i]);
           }
           else if(str[i]==')'){
            pop(s);
            //pop(s);
           }


    }
    //printf("%d",s->top);
    if(s->top==-1){
        printf("match");
    }
    else{
        printf("mismatch");
    }


}
//void display(struct st *s){
  //  for(int i=0;i<4;i++){
    //    printf("%c",s->arr[i]);
    //}
//}
int main(){
    char str[50];

    printf("enter exp");
    gets(str);
    struct st s;
    initialize(&s);
    //display(&s);
    check(&s,str);
}



