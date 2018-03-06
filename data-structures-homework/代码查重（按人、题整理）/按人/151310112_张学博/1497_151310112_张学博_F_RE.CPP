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
const int maxn=200;
const int inf=9999;
int dist[maxn][maxn];
int n,m;
void floyed()
{
    for(int k=1;k<=n;k++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int i=1;i<=n;i++)
            {
              
              
                  dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        int x,y,v;
        memset(dist,inf,sizeof(dist));
      for(int i=1;i<=n;i++)
      {
          dist[i][i]=0;
      }
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&x,&y,&v);
           dist[x][y]=v;
        }
        int s,e,vv;
        floyed();
        int k=(n-1)/3;
        while(k--)
        {
            scanf("%d%d%d",&s,&e,&vv);

        if(dist[s][e]==vv)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
        }
    }
    return 0;
}

