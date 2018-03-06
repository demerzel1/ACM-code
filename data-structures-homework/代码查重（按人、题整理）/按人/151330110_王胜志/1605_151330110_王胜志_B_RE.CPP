#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef pair<int,int> Eage;
vector<Eage> S[1005];
int n,m,L;
int Num[1005];
void DFS(int a,int sum,int &M)
{
    if(sum>L)
        return;
    if(M<Num[a])
        M=Num[a];
     int i;
     for(i=0;i<S[a].size();i++)
     {
         if(S[a][i].first!=a)
         {
             DFS(S[a][i].first,sum+S[a][i].second,M);
         }
     }

}
int main()
{
    Eage temp;
    int i,j;
    int x,y;
    long long z;
    while(scanf("%d%d%d",&n,&m,&L))
      {
          for(i=1;i<=m;i++)
          {
              scanf("%d%d%lld",&x,&y,&z);
              temp.first=y;
              temp.second=z;
              S[x].push_back(temp);
               temp.first=x;
               temp.second=z;
               S[y].push_back(temp);
          }
          for(i=1;i<=n;i++)
          {
              scanf("%d",&Num[i]);
          }
          int sum=0;
          int M=0;
          DFS(1,sum,M);
          printf("%d\n",M);
          for(i=0;i<=n;i++)
          {
              if(!S[i].empty())
                S[i].clear();
          }
      }
  return 0;
}

