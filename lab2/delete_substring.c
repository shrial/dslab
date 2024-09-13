
#include<stdio.h>
int main(){
    char str[100],subs[100];
printf("enter first string");
gets(str);
printf("enter sub string");
gets(subs);
int len,sublen,i,j,count=0;
for(i=0;str[i]!='\0';i++);
for(j=0;subs[j]!='\0';j++);
len=i,sublen=j;
for(int k=0;k<len;k++){
    for(int l=0;l<sublen;l++){
        if(str[k+l]==subs[l]){
                count+=1;
        }
        else{
            break;}
        }
        if(count==sublen){

                for(int p=0;p<count;p++){
        for(int m=k;m<len;m++){
                str[m]=str[m+1];
            }}
    }
    count=0;
}
printf("string after substring deletion is");
puts(str);
}
