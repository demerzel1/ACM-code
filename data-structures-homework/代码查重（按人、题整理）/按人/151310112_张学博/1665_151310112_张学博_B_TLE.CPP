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
const int maxn=1010;
const int inf=10000;
long long dist[maxn][maxn];
long long value[maxn];
long long n,m,l;
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

  while(~scanf("%lld%lld%lld",&n,&m,&l))
    {
        long long  x,y,v;
        memset(dist,inf,sizeof(dist));
      for(long long i=1;i<=n;i++)
      {
          dist[i][i]=0;
      }
        for(long long i=0;i<m;i++)
        {
            scanf("%lld%lld%lld",&x,&y,&v);
           dist[x][y]=v;
        }
        floyerd();
        for(long long i=1;i<=n;i++)
        {

            scanf("%lld",&value[i]);
        }
        long long maxx=value[1];
        for(int i=2;i<=n;i++)
        {
            if(dist[1][i]<=l&&value[i]>maxx)
            {
                maxx=value[i];
            }
        }
       printf("%lld\n",maxx);
    }
    return 0;
}

