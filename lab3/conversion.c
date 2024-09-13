//is isFull,isEmpty display functions needed?
#include<stdio.h>
int top=-1;

int isempty(int arr[]){
if (top==-1){
return 1;}
else{
    return 0;
}
}

int isfull(int arr[],int len){
if (top==(len-1)){
    return 1;}
    else{
        return 0;
    }
}

void push(int arr[],int num){
 //if (isfull(arr,len));
 arr[++top]=num;
}
void push_(char arr[],char ch){
 //if (isfull(arr,len));
 arr[++top]=ch;
}

int pop(int arr[]){
    int popped = arr[top--];
    return popped;
}
char pop_(char arr[]){
    char popped = arr[top--];
    return popped;
}


void con_bin(int arr[],int num){
    if (num==0){
        printf("%d",num);
    }
    while(num>0){
        push(arr,(num%2));
        num/=2;
    }
    while(top!=-1){
        int popped=pop(arr);
        printf("%d",popped);
    }
}
void con_oct(int arr[],int num){
    if (num==0){
        printf("%d",num);
    }
    while(num>0){
        push(arr,(num%8));
        num/=8;
    }
    while(top!=-1){
        int popped=pop(arr);
        printf("%d",popped);
    }
}

void con_hex(char arr[],int num){
    if (num==0){
        printf("%d",num);
    }
    while(num>0){
            int rem=num%16;
        if(rem<10){
            push_(arr,(rem+48));
        }
        else{
            push_(arr,(rem+55));
        }
        num/=16;
    }
    while(top!=-1){
        char popped=pop_(arr);
        printf("%c",popped);
    }
}

void display(int arr[],int len){
    if(isempty(arr)){
    printf("stack is empty\n");}
    else{
    for (int i=0;i<=top;i++){
        printf("%d",arr[i]);

    }}
    printf("\n");
}

void main(){
int num;
char base;
printf("enter a decimal number");
scanf("%d",&num);
while (getchar() != '\n');
int arr[50];
char hex[50];
printf("enter the base(b/o/h)");
scanf("%c",&base);
if(base=='b'){
        printf("number in binary form is :\n");
    con_bin(arr,num);
}
else if(base=='o'){
printf("number in octal form is :\n");
    con_oct(arr,num);
}
else if(base=='h'){
printf("number in hexadecimal form is :\n");
    con_hex(hex,num);
}
else{
printf("invalid base");
}
}
