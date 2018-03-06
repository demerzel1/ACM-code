#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;

LL Rel[1010][1010];
LL n,m,c;
LL Eme[1010];
LL max_eme;
bool vis[1010];

void dfs(int cur,LL cur_mon)
{
    if(Eme[cur]>max_eme) max_eme=Eme[cur];
    vis[cur]=true;
    for(int i=0;i<n;i++)
    {
        if(Rel[cur][i]!=-1&&vis[i]==false&&cur_mon>=Rel[cur][i]){
            dfs(i,cur_mon-Rel[cur][i]);
        }
    }
    return ;
}

int main()
{
    while(EOF!=scanf("%lld%lld%lld",&n,&m,&c))
    {
        memset(vis,false,sizeof(vis));
        memset(Rel,-1,sizeof(Rel));
        max_eme=-1;
        for(LL i=0;i<m;i++){
            LL t1,t2,t3;
            scanf("%lld%lld%lld",&t1,&t2,&t3);
            Rel[t1][t2]=t3;
            Rel[t2][t1]=t3;
        }
        for(LL i=1;i<=n;i++){
            scanf("%lld",&Eme[i]);
        }
        max_eme=0;
        dfs(1,c);
        printf("%lld\n",max_eme);
    }
    return 0;
}

