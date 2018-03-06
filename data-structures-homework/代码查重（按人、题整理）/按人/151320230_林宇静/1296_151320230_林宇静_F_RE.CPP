#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int inf=1e8;
int n,m,line[1100][1100],dista[1100],sta,en;
long long sum;
void bellman()
{
    int flag=1;
    for(int i=1;i<n&&flag;i++){
        flag=0;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(line[k][j]&&dista[k]!=inf){
                    if(dista[j]>dista[k]+line[k][j]){
                        dista[j]=dista[k]+line[k][j];
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
        memset(dista,0,sizeof(dista));
        memset(line,0,sizeof(line));
        int u,v,w;
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&u,&v,&w);
            line[u][v]=line[v][u]=w;
        }
        scanf("%d%d%lld",&sta,&en,&sum);
        for(int i=1;i<=n;i++)
            dista[i]=inf;
        dista[sta]=0;
        bellman();
        if(dista[en]==sum)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

