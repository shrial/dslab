//in i) didnt check if element if there or no
//meow meow
//please assign *head=NULL else program wont work

#include <stdio.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node* create(int d){
    struct Node *newnode=(struct Node* )malloc(sizeof(struct Node*));
    newnode->data=d;
    newnode->next=NULL;
    return newnode;
}
struct Node* addbef(struct Node *h, struct Node *newn,int ele){
    if(h==NULL){
        h=newn;
    }
    else if(h->next==NULL && h->data==ele){
        newn->next=h;
        h=newn;
    }
    else{
            //printf("hi");
        struct Node *temp=h;
        struct Node *temp2=temp->next;
        for(int i=0;(temp->next)!=NULL;i++){
            if(temp2->data==ele){
                newn->next=temp->next;
                temp->next=newn;
                break;
            }
            else{
                temp2=temp2->next;
                temp=temp->next;
            }
        }
    }
    return h;
}
void main(){
    struct Node *head=NULL;
    int resp=1,ele,e;

        printf("enter ele");
        scanf("%d",&ele);
        struct Node *newnode=create(ele);
        printf("enter the element before which");
        scanf("%d",&e);
        head=addbef(head,newnode,e);
        //printf("%d",head->data);
        struct Node *n2=create(2);
        head=addbef(head,n2,ele);
        //head->next->data = 1;
        //printf("%d",head->next->data);
        struct Node *n3=create(1);
        head=addbef(head,n3,2);
        //printf("%d",head->data);
        struct Node *temp=head;
        for(int i=0;temp!=NULL;i++){
            printf("%d  ",temp->data);
            temp=temp->next;
        }

}
