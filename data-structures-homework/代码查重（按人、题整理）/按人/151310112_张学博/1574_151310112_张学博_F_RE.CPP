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
const int maxn=105;
const int inf=10000;
int dist[maxn][maxn];
int n,m;
void floyerd()
{
    for(int i=1;i<=n;i++)
    for(int k=1;k<=n;k++)
    for(int j=1;j<=n;j++)
    {
        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
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
        floyerd();
        int k=(n-1)/3;
        for(int i=0;i<k;i++)
        {
            scanf("%d%d%d",&x,&y,&v);
            if(dist[x][y]==v)
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

