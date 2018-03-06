#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

double a[25][25][25],p[25][25][25];

void path(int s,int i,int j){
    if(s==0){
        printf("%d",i);
        return;
    }
    path(s-1,i,p[s][i][j]);
    printf(" %d",j);
}
void floyd(int n){
    for(int s=2;s<=n;s++){
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                 for(int j=1;j<=n;j++){
                if(a[s-1][i][k]*a[1][k][j]>a[s][i][j]){
                    a[s][i][j]=a[s-1][i][k]*a[1][k][j];
                    p[s][i][j]=k;
                }
            }
        }
    }


    for(int i=1;i<=n;i++){
        if(a[s][i][i]>1.01){
            path(s-1,i,p[s][i][i]);
            printf(" %d",i);
            return;
        }
    }
    }
    printf("no arbitrage sequence exists");
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j){
                    a[1][i][j]=1;
                }else{
                    scanf("%lf",&a[1][i][j]);
                }
                p[1][i][j]=i;
            }
        }
        floyd(n);
        printf("\n");
    }
    return 0;
}
