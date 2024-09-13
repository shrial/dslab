#include<stdio.h>
void main(){
char str1[100],str2[50];
int len1,len2,i,j;
printf("enter first string");
gets(str1);
printf("enter second string");
gets(str2);
for(i=0;str1[i]!='\0';i++);
len1=i;
for(j=0;str2[j]!='\0';j++);
len2=j;
if((len1+len2)<100){
    for(int k=len1;str2[k-len1]!='\0';k++){
        str1[k]=str2[k-len1];
    }
    str1[(len1+len2)]='\0';
}
printf("combined string is ");
puts(str1);
}
