#include<stdio.h>
int front=0,rear=-1;
int isempty(){
    if(rear==-1){
        return 1;
    }
    else{
        return 0;
    }

}
int isfull(int len){
    if(rear==(len-1)){
        return 1;
    }
    else{
        return 0;
    }
}
void enqueue(int arr[],int val,int len){
    if(isfull(len)){
        printf("queue is full\n");
    }
    else{
        arr[++rear]=val;
    }
}

void dequeue(int arr[],int len){
    if(isempty()){
       printf("queue is empty\n");
    }
        else{
                printf("popped element is %d",arr[0]);
                for(int i=0;i<(len-1);i++){
                    arr[i]=arr[i+1];

                }
                rear--;
            }
        }

void getfirst(int arr[]){
    if(isempty()){
        printf("queue is empty\n");
    }
    else{
        printf("element at front is %d\n",arr[front]);
    }
}

int main(){
    int len,ch,val;
    int resp=1;
    printf("enter the size of the queue");
    scanf("%d",&len);
    int q[len];
    while(resp==1){
        printf("enter your choice\n 1.enqueue  2. dequeue 3.get first element ");
        scanf("%d",&ch);
        if(ch==1){
            printf("enter the element");
            scanf("%d",&val);
            enqueue(q,val,len);
        }
        else if(ch==2){
            dequeue(q,len);
        }
        else{
            getfirst(q);
        }
        printf("do you want to continue(0/1)");
        scanf("%d",&resp);

    }
}