#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <algorithm>
#include <hash_map>
#define MAXN 1000
using namespace std;
int N,M,L;
int maps[MAXN][MAXN];
int val[MAXN];
int can[MAXN];
int mam;
int dfs(int u,int money)
{
    if(money<0) return 0;
    for(int i=u+1; i<N; i++)
    {
        if(maps[u][i]&&(money-=maps[u][i])>=0)
        {
            can[i]=1;
            if(mam==maps[u][i]) return mam;
            dfs(i,money);
        }
    }
    return 0;
}

int main()
{
    int s,t,cost;
    while(scanf("%d%d%d",&N,&M,&L)!=EOF)
    {
        memset(can,0,sizeof(can));
        memset(val,0,sizeof(val));
        memset(maps,0,sizeof(maps));
        mam=0;
        for(int i=0; i<M; i++)
        {
            scanf("%d%d%d",&s,&t,&cost);
            mam=max(mam,cost);
            maps[s][t]=cost;
        }
        can[1]=1;



        for(int i=1; i<=N; i++)
        {
            cin>>val[i];
        }
        int maxnum=dfs(1,L);
        for(int i=1;i<=N;i++)
        {
            if(can[i]) maxnum=max(maxnum,val[i]);
        }
        cout<<maxnum<<endl;

    }

    return 0;
}

