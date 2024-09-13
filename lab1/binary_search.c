#include<stdio.h>
int main(){
int n,flag=0,key,pos=0,low=0,high=(n-1),mid;
printf("enter size of array");
scanf("%d",&n);
int arr[n];
for(int i=0;i<n;i++){
    printf("enter the element");
    scanf("%d",&arr[i]);
}
printf("enter  the element to be searched");
scanf("%d",&key);
for (int i=0;low<=high;i++){
    mid=(low+high)/2;
    if(arr[mid]==key){
        flag=1;
        pos=(mid+1);
        break;
    }
    else if(key<arr[mid]){
        high=(mid-1);
    }
    else if(key>arr[mid]){
        low=(mid+1);
    }
}
if(flag==1)
    printf("element found at position %d",pos);
else
    printf("element not found");
}


