#include<stdio.h>
void main(){
int n,temp;
printf("enter size of array");
scanf("%d",&n);
int arr[n];
for(int i=0;i<n;i++){
    printf("enter the element");
    scanf("%d",&arr[i]);
}

for(int i=0;i<(n-1);i++){
    for(int j=0;j<(n-1-i);j++){
        if(arr[j]>arr[j+1]){
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
}
printf("sorted array:");
for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
}


}

