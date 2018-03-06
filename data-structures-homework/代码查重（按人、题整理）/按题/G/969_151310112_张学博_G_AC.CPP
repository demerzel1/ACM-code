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
const int maxx=110;
int link[maxx][maxx];
int visited[maxx];
int girl[maxx];
int n,m;
int Find(int x)
{
    if(visited[x]==1)
    {
        return 0;
    }
    else
    {
        visited[x]=1;
        for(int i=1;i<=m;i++)
        {
            if(link[x][i])
            {
                if(girl[i]==-1||Find(girl[i]))
                {
                    girl[i]=x;
                    return 1;
                }
            }
        }
    }
    return 0;
}
int main()
{
    int k;
   while(~scanf("%d%d",&n,&m))
   {
       memset(link,0,sizeof(link));
       memset(girl,-1,sizeof(girl));
       int x,y;
       scanf("%d",&k);
       for(int i=0;i<k;i++)
       {
           scanf("%d%d",&x,&y);
           link[x][y]=1;
       }
       int ans=0;
       for(int i=1;i<=n;i++)
       {
           memset(visited,0,sizeof(visited));
           if(Find(i))
           {
               ans++;
           }
       }
       printf("%d\n",ans);
   }
    return 0;
}

