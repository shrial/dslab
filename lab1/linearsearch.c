#include<stdio.h>
int main(){
int n,flag=0,key,pos=0;
printf("enter size of array");
scanf("%d",&n);
int arr[n];
for(int i=0;i<n;i++){
    printf("enter the element");
    scanf("%d",&arr[i]);
}
printf("enter  the element to be searched");
scanf("%d",&key);
for(int i=0;i<n;i++){
    if(arr[i]==key){
        flag=1;
        pos=(i+1);
        break;
    }
}
if(flag==1)
    printf("element found at position %d",pos);
else
    printf("element not found");
}
