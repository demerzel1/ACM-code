#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define max1 110
using namespace std;
int relation[max1][max1];
int flag[max1];int boy[max1],m,n;
int canfind(int t)
{
    for(int i=1;i<=m;i++)
    {
        if(flag[i]==0&&relation[t][i])
        {
            flag[i]=1;
            if(boy[i]==-1||canfind(boy[i]))
            {
                boy[i]=t;
                return 1;
            }
        }
    }
    return 0;
}
void solve()
{
  int nk=0;
  for(int i=1;i<=n;i++)
  {
      memset(flag,0,sizeof(flag));
      if(canfind(i))
        nk++;
  }
  printf("%d\n",nk);
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {   memset(relation,0,sizeof(relation));
        memset(boy,0xff,sizeof(boy));
        int ku,x,y;
        scanf("%d",&ku);
        for(int i=0;i<ku;i++)
        {
           scanf("%d%d",&x,&y);
           relation[x][y]=1;
        }
        solve();
    }
    return 0;
}

