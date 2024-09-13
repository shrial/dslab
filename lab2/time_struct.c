#include<stdio.h>
struct time{
int hour;
int min;
int sec;
};
void read(struct time* p1,struct time* p2){
    printf("enter the hour, minute and second for time 1");
    scanf("%d %d %d",&p1->hour,&p1->min,&p1->sec);
    printf("enter the hour, minute and second for time 2");
    scanf("%d %d %d",&p2->hour,&p2->min,&p2->sec);
}
void display(struct time t1,struct time t2){
    printf("first time entered is %d:%d:%d\n",t1.hour,t1.min,t1.sec);
    printf("second time entered is %d:%d:%d\n",t2.hour,t2.min,t2.sec);
}
struct time convert(int total){
    struct time res;
    res.hour=total/3600;
    total%=3600;
    res.min=total/60;
    res.sec=total%60;
    return res;
}

struct time sub(struct time t1,struct time t2){
    int total;
    int time1= (t1.hour*3600)+(t1.min*60)+(t1.sec);
    int time2= (t2.hour*3600)+(t2.min*60)+(t2.sec);
    if (time1>time2)
    total = time1-time2;
    else total=time2-time1;
    struct time res=convert(total);
    return res;
}
struct time add(struct time t1,struct time t2){
    int total;
    int time1=(t1.hour*3600)+(t1.min*60)+t1.sec;
    int time2= (t2.hour*3600)+(t2.min*60)+(t2.sec);
    total=time1+time2;
    struct time res=convert(total);
    return res;
}

int main(){
struct time t1,t2,diff,sum,*p1,*p2;
p1=&t1,p2=&t2;
read(p1,p2);
display(t1,t2);
diff=sub(t1,t2);
printf("the result of subtraction of the two times is %d:%d:%d \n",diff.hour,diff.min,diff.sec);
sum=add(t1,t2);
printf("the result of addition of the two times is %d:%d:%d\n ",sum.hour,sum.min,sum.sec);
}
