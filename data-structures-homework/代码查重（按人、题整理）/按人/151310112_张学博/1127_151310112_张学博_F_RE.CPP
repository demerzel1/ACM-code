#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include <map>
#include <list>
#include <cstring>
#include <cmath>
using namespace std;
const int maxx=200;
int dist[maxx][maxx];
const int inf=9999;
int n,m;
void floyed()
{
    for(int k=1;k<=n;k++)
    for(int j=1;j<=n;j++)
    for(int i=1;i<=n;i++)
    {
        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
    }
}
int main()
{
    while(scanf("%d%d",&n,&m))
    {
        memset(dist,inf,sizeof(dist));
        for(int i=1;i<=n;i++)
        {
            dist[i][i]=0;
        }
        int u,v,value;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&value);
            dist[u][v]=value;
            dist[v][u]=value;
        }
        floyed();
        int start,ends,vv;
       scanf("%d%d%d",&start,&ends,&vv);
       if(dist[start][ends]!=vv)
       {
           printf("NO\n");
       }
       else
       {
           printf("YES\n");
       }

    }
    return 0;
}

