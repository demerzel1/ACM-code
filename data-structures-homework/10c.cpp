#include<cstdio>
#include<iostream>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;
int x[110][55],y[110][55];
int nx[55],ny[55];
int N;

int total(int i){
    int flag=1;
    for(int j=0;j<i;j++){
        flag=1;
        for(int k=1;k<=N;k++){
    //        printf("j:x[%d]=%d y[%d]=%d\n",k,x[j][k],k,y[j][k]);
     //       printf("i:x[%d]=%d y[%d]=%d\n",k,x[i][k],k,y[i][k]);
            if(x[j][k]!=x[i][k]||y[j][k]!=y[i][k]){
                flag=0;
                break;
            }
        }
        if(flag==1)
            break;
    }
    if(flag==1)
        return 1;
    else
        return 0;
}
int zuoxuan(int i){
    int flag=1;
    for(int j=0;j<i;j++){
        flag=1;
        for(int k=1;k<=N;k++){
            if(x[j][k]!=y[i][k]||y[j][k]!=x[i][k]){
                flag=0;
                break;
            }
        }
        if(flag==1)
            break;
    }
    if(flag==1)
        return 1;
    else
        return 0;
}
int youxuan(int i){
    int flag=1;
    for(int j=0;j<i;j++){
        flag=1;
        for(int k=1;k<=N;k++){
            if(x[j][k]!=y[i][N-k+1]||y[j][k]!=x[i][N-k+1]){
                flag=0;
                break;
            }
        }
        if(flag==1)
            break;
    }
    if(flag==1)
        return 1;
    else
        return 0;
}
int daozhuan(int i){
    int flag=1;
    for(int j=0;j<i;j++){
        flag=1;
        for(int k=1;k<=N;k++){
     //      printf("j:x[%d]=%d y[%d]=%d\n",k,x[j][k],k,y[j][k]);
       //     printf("i:x[%d]=%d y[%d]=%d\n",k,x[i][k],k,y[i][k]);
            if(x[j][k]!=x[i][N-k+1]||y[j][k]!=y[i][N-k+1]){
                flag=0;
                break;
            }
        }
        if(flag==1)
            break;
    }
    if(flag==1)
        return 1;
    else
        return 0;
}
int cmp(int i){
   //   printf("%d %d %d %d\n",total(i),zuoxuan(i),youxuan(i),daozhuan(i));
    if(total(i)||zuoxuan(i)||youxuan(i)||daozhuan(i)){
      //  printf("%d %d %d %d\n",total(i),zuoxuan(i),youxuan(i),daozhuan(i));
        return 1;
    }

    else return 0;
}
int main(){


    while(scanf("%d",&N)){
        if(N==0)
            break;
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
        memset(nx,0,sizeof(nx));
        memset(ny,0,sizeof(ny));
        for(int i=0;i<2*N;i++){
            int a,b;
            char c;
            scanf("%d%d",&a,&b);
            getchar();
            c=getchar();
            if(c=='+'){
                nx[a]++;
                ny[b]++;
            }
            if(c=='-'){
                nx[a]--;
                ny[b]--;
            }
            for(int j=1;j<=N;j++){
                x[i][j]=nx[j];
                y[i][j]=ny[j];
            }
        }
        int f=0;
        for(int i=1;i<2*N;i++){
            if(cmp(i)){
         //       printf("i=%d\n",i);
                f=1;
                int q=i%2+1;
            //    printf("q=%d\n",q);
                if(q==1)
                    q=2;
                else if(q==2)
                    q=1;
                printf("Player %d wins on move %d\n",q,i+1);
                break;
            }
        }
        if(f==0)
            printf("Draw\n");
    }
    return 0;
}
