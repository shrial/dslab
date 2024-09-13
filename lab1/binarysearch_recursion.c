#include<stdio.h>
int binary(int arr[],int h,int l,int key){
    int mid;
    if(h>l){
        mid=(h+l)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]<key){
            binary(arr,h,(mid+1),key);
        }
        else{
            binary(arr,(mid-1),l,key);
        }
    }
    else{
        return -1;
    }
}
void main(){
    int n,key;
    printf("enter size of array");
scanf("%d",&n);
int arr[n];
for(int i=0;i<n;i++){
    printf("enter the element");
    scanf("%d",&arr[i]);
}
printf("enter  the element to be searched");
scanf("%d",&key);
int f=binary(arr,(n-1),0,key);
if(f==-1) printf("element not found");
else{
    printf("element found at pos %d",(f+1));
}
}
