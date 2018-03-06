#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;
vector<int> Boy[105];
int G[105];
bool Y[105];
int n,m;

bool DFS(int i)
{
    int j;
    for(j=0;j<Boy[i].size();j++)
    {
        if(!Y[Boy[i][j]])
        {
            Y[Boy[i][j]]=true;
            if(G[Boy[i][j]]==-1||DFS(G[Boy[i][j]]))
            {
                G[Boy[i][j]]=i;
                return true;
            }
        }
    }
    return false;
}
void Solu()
{
    int i,num;
    num=0;
    fill(G,G+103,-1);
    for(i=1;i<=n;i++)
    {
        fill(Y,Y+103,false);
        if(DFS(i))
            num++;
    }
    printf("%d\n",num);
}
int main()
{
    int k;
    int i,j;
    int x,y;
   while(scanf("%d%d",&n,&m)!=EOF)
   {
       scanf("%d",&k);
       for(i=1;i<=k;i++)
       {
          scanf("%d%d",&x,&y);
          Boy[x].push_back(y);
       }
       Solu();
       for(i=1;i<=n;i++)
       {
           if(!Boy[i].empty())
            Boy[i].clear();
       }
   }
  return 0;
}

