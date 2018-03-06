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

void dfs(int u,int money)
{

    for(int i=u+1; i<N; i++)
    {
        if(maps[u][i]&&(money-=maps[u][i])>=0)
        {
            can[i]=1;
            dfs(i,money);
        }
    }
}

int main()
{
    int s,t,cost;
    while(cin>>N>>M>>L)
    {
        memset(can,0,sizeof(can));
        memset(val,0,sizeof(val));
        memset(maps,0,sizeof(maps));
        for(int i=0; i<M; i++)
        {
            cin>>s>>t>>cost;
            maps[s][t]=cost;
        }
        can[1]=1;
        dfs(1,L);


        for(int i=1; i<=N; i++)
        {
            cin>>val[i];
        }
        int maxnum=0;
        for(int i=1;i<=N;i++)
        {
            if(can[i]) maxnum=max(maxnum,val[i]);
        }
        cout<<maxnum<<endl;

    }

    return 0;
}

