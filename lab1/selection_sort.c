#include<stdio.h>
int main(){
int n,small,pos;
printf("enter size of array");
scanf("%d",&n);
int arr[n];
for(int i=0;i<n;i++){
    printf("enter the element");
    scanf("%d",&arr[i]);
}
for(int i=0;i<(n-1);i++){
small=arr[i];
    for(int j=(i+1);j<n;j++){

        if(arr[j]<=small){
        small=arr[j];
        pos=j;}
    }
    printf("%d",small);
    arr[pos]=arr[i];
    arr[i]=small;

    }
printf("sorted array:");
for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
}
}
