#include<stdio.h>
int main(){
    char str[100],subs[100];
printf("enter first string");
gets(str);
printf("enter sub string");
gets(subs);
int len,sublen,i,j,pos;
for(i=0;str[i]!='\0';i++);
for(j=0;subs[j]!='\0';j++);
len=i,sublen=j;
printf("enter the position to add the substring");
scanf("%d",&pos);
for(int k=len;k>=(pos-1);k--){
    str[k+sublen]=str[k];

}
for(int m=(pos-1);m<(pos-1+sublen);m++){
    str[m]=subs[m-pos+1];
}
printf("string after inserting substring is ");
puts(str);
}
