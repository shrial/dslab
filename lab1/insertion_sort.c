#include<stdio.h>
int main(){
int n,temp;
printf("enter size of array");
scanf("%d",&n);
int arr[n];
for(int i=0;i<n;i++){
    printf("enter the element");
    scanf("%d",&arr[i]);
}
for(int end=1;end<n;end++ ){
    if(arr[end]<arr[end-1]){
        for(int i=end;arr[i]<arr[i-1];i--){
            temp=arr[i];
            arr[i]=arr[i-1];
            arr[i-1]=temp;
        }
    }
}
printf("sorted array:");
for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
}

}
