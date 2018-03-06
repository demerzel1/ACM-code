#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int inf=1e8;
int n,m,line[1005][1005],distant[1005],start,en,sum;
void bellman()
{
    int flag=1;
    for(int i=1;i<n&&flag;i++){
        flag=0;
        for(int j=1;j<=n;j++){
            for(int k=1;k<n;k++){
                if(line[k][j]&&distant[k]!=inf){
                    if(distant[j]>distant[k]+line[k][j]){
                        distant[j]=distant[k]+line[k][j];
                    }
                    flag=1;
                }
            }
        }
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(distant,0,sizeof(distant));
        memset(line,0,sizeof(line));
        int u,v,w;
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&u,&v,&w);
            line[u][v]=w;
        }
        scanf("%d%d%d",&start,&en,&sum);
        for(int i=1;i<=n;i++)
            distant[i]=inf;
        distant[start]=0;
        bellman();
        if(distant[en]==sum)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

