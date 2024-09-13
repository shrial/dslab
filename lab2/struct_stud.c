//f bro this aint working
#include<stdio.h>
#include<string.h>
//read,display and sort
struct student{
char name[50];
int rollno;
char grade;
};
int n;
void read(struct student stu[],int n){

    for(int i=0;i<n;i++){
        printf("enter name of student");
        fgets(stu[i].name,sizeof(stu[i].name),stdin);
        stu[i].name[strcspn(stu[i].name, "\n")] = '\0';

        printf(" enter roll number");
        scanf("%d",&stu[i].rollno);
        while (getchar() != '\n');
        printf(" enter grade");
        scanf("%c",&stu[i].grade);
        while (getchar() != '\n');
    }

}
void display(struct student stu[],int n){
    for(int i=0;i<n;i++){
        printf("\n name, roll number and grade of student are");
        printf("%s %d %c",stu[i].name,stu[i].rollno,stu[i].grade);
    }
}
int main(){
    printf("enter number of students");
    scanf("%d",&n);
    struct student stu[n];
    while (getchar() != '\n');
struct student *p;
p=stu;
read(stu,n);
display(stu,n);

}
