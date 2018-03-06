#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
#define Max 10000000
double gh[1000][1000];
int N,M;

double mintree(){
    int i,j,k;
    double m,len=0,Min[1000];
    int vis[1000]={0};
    vis[0]=1;
    for(i=0;i<N;i++)
        Min[i]=gh[0][i];
    for(i=1;i<N;i++){
        for(j=1,m=Max;j<N;j++)
        if(m>Min[j]&&!vis[j]){
            m=Min[j];
            k=j;
        }
        len+=m;
        vis[k]=1;
        for(j=1;j<N;j++)
            if(gh[k][j]<Min[j])
                Min[j]=gh[k][j];
    }
    return len;
}

int main(){
    int i,j,k;
    double p[1000][2],d;
    while(scanf("%d",&N)!=EOF){
        for(i=0;i<N;i++){
            scanf("%lf%lf",&p[i][0],&p[i][1]);
            for(j=i;j>=0;j--){
                d=sqrt((p[i][0]-p[j][0])*(p[i][0]-p[j][0])+(p[i][1]-p[j][1])*(p[i][1]-p[j][1]));
                gh[i][j]=d;
                gh[j][i]=d;
            }
        }
        scanf("%d",&M);
        for(i=0;i<M;i++){
            scanf("%d%d",&j,&k);
            gh[j-1][k-1]=0;
            gh[k-1][j-1]=0;
        }
        printf("%.2lf\n",mintree());
    }
    return 0;
}
