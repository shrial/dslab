#include<stdio.h>
int main(){
char str1[100],str2[100];
printf("enter first string");
gets(str1);
printf("enter second string");
gets(str2);
for(int i=0;str1[i]!='\0'&&str2[i]!='\0';i++){
    int a=str1[i];
    int b=str2[i];
    if(a>b){
        printf("%s comes after %s",str1,str2);
        break;}
    else if(a<b){
        printf("%s comes before %s",str1,str2);
        break;
    }
}
}
