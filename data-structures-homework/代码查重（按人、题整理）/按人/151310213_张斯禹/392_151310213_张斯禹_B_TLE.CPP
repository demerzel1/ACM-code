#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#include <functional>
#include <cmath>
#include <memory.h>
#include <cstdio>
#include <sstream>

using namespace std;

#define MAXN 1005

int maxeme;
int m,n,l;
vector <pair<int,int> > G[MAXN];
int eme[MAXN];

void dfs(int now,int money,int last)
{
    if(money>l)
        return;
    if(eme[now]>maxeme)
        maxeme=eme[now];
    for(int i=0;i<G[now].size();i++)
    {
        if(G[now][i].first!=last)
            dfs(G[now][i].first,money+G[now][i].second,now);
    }
}

int main()
{
    while(cin>>n>>m>>l)
    {
        int p1,p2,value;
        for(int i=0;i<n;i++)
            G[i].clear();
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&p1,&p2,&value);
            G[p1-1].push_back({p2-1,value});
            G[p2-1].push_back({p1-1,value});
        }
        for(int i=0;i<n;i++)
            scanf("%d",&eme[i]);
        maxeme=0;
        dfs(0,0,0);
        printf("%d\n",maxeme);
    }
    return 0;
}

