#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
int used[200];
int line[200][200];
int girl[200];
int n,m,y;
int a,b;
bool Find(int x)
{
    for(int j=1;j<=m;j++)
    {
        if(line[x][j]==1&&used[j]==0)
        {
            used[j]=1;
            if(girl[j]==0||Find(girl[j]))
            {
                girl[j]=x;
                return true;
            }
        }
    }
    return false;
}
int main()
{
   while(~scanf("%d%d",&n,&m))
   {
       int ans=0;
       memset(girl,0,sizeof(girl));
       memset(line,0,sizeof(line));
       scanf("%d",&y);
       for(int i=1;i<=y;i++)
       {
           scanf("%d%d",&a,&b);
           line[a][b]=1;
       }
       for(int i=1;i<=n;i++)
       {
           memset(used,0,sizeof(used));
           if(Find(i))ans++;
       }
       printf("%d\n",ans);
   }
    return 0;
}

