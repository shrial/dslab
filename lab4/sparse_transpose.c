#include<stdio.h>
struct sp{
    int row;
    int col;
    int val;
};
void sp_rep(int arr[5][5],int m,int n,struct sp spa[]){
    int t=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]!=0){
                spa[t].row=i;
                spa[t].col=j;
                spa[t].val=arr[i][j];
                t++;
            }
        }
    }
    //st=spa[0];
}
void transpose(int n,struct sp spa[]){
    int rowterm[n],startpos[n];
    for (int i = 0; i < n; i++) {
        rowterm[i] = 0;
        startpos[i] = 0;
    }
    for(int i=1;i<=(spa[0].val);i++){
        rowterm[spa[i].col]++;
    }

    startpos[0]=1;
    for(int i=1;i<n;i++){
        startpos[i]=startpos[i-1]+rowterm[i-1];
    }
    struct sp trans[spa[0].val+1];
    trans[0].row=spa[0].col;
    trans[0].col=spa[0].row;
    trans[0].val=spa[0].val;

    for(int i=1;i<=(spa[0].val);i++){
       int j=startpos[spa[i].col];
        trans[j].row=spa[i].col;
        trans[j].col=spa[i].row;
        trans[j].val=spa[i].val;
        startpos[spa[i].col]++;
    }
    for(int i=1;i<=(spa[0].val);i++){
        printf("%d",trans[i].row);
        printf("%d",trans[i].col);
        printf("%d",trans[i].val);
        //while(getchar()!='\n');
    }

}
int main(){
    int m,n,count=0;
    printf("enter number of rows");
    scanf("%d",&m);
    printf("enter number of columns");
    scanf("%d",&n);
    int arr[m][n];
    //int **arr=(int **)malloc(m*(sizeof(int*)));
    //for(int i=0;i<m;i++){
    //    arr[i]=(int*)malloc(n*sizeof(int));
    //}
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("enter the element");
            scanf("%d",&arr[i][j]);
            if(arr[i][j]!=0){
                count++;
            }
        }
    }
    //printf("here");
    struct sp spa[count+1];
    spa[0].row=m,spa[0].col=n,spa[0].val=count;
    sp_rep(arr,m,n,spa);
    transpose(n,spa);

return 0;
}
