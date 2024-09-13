#include<stdio.h>
void main(){
int i;
char str[50];
printf("enter a string");
gets(str);
for(i=0;str[i]!='\0';i++);
printf("length of string is %d",i);
}
