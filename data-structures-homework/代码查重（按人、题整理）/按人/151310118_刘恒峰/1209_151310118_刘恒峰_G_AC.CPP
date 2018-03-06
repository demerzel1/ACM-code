#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <queue>
#include <list>
#include <cstring>
#include <cmath>

const int maxn=105;

using namespace std;

bool G[maxn][maxn];
int xM[maxn],yM[maxn];
bool used[maxn];
int n,m;

void add_edge(int u,int v)
{
    G[u][v]=true;
}
bool dfs(int v)
{
    for (int i=1;i<=m;i++)
    {
        if (G[v][i] && !used[i])
        {
            used[i]=true;
            if (yM[i]<0 || dfs(yM[i]))
            {
                xM[v]=i;
                yM[i]=v;
                return true;
            }
        }
    }
    return false;
}
int bipartite_matching()
{
    int res=0;
    memset(xM,-1,sizeof(xM));
    memset(yM,-1,sizeof(yM));
    for (int i=1;i<=n;i++)
    {
        if (xM[i]<0)
        {
            memset(used,0,sizeof(used));
            if (dfs(i))
            {
                res++;
            }
        }
    }
    return res;
}


int main()
{
    while (cin>>n>>m)
    {
        int k;
        cin>>k;
        int x,y;
        memset(G,0,sizeof(G));
        for (int i=0;i<k;i++)
        {
            cin>>x>>y;
            add_edge(x,y);
        }
        int ans=bipartite_matching();
        cout<<ans<<endl;
    }
    return 0;
}

