#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
const long long MAX=2147483649;
typedef struct Tree{
    int l;
    int r;
    long long co;
}Tree;
vector<Tree> T;
int n,m,L;
int Num[1005];
long long Dis[1005];
void Solu()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        Dis[i]=MAX;
    }
    Dis[1]=0;
    for(i=1;i<n;i++)
    {
        for(j=0;j<T.size();j++)
        {
            if(Dis[T[j].l]+T[j].co<Dis[T[j].r])
            {
                Dis[T[j].r]=Dis[T[j].l]+T[j].co;
            }
        }
    }
    int cri=0;
    for(i=1;i<=n;i++)
    {
        if(Dis[i]<=L)
        {
            if(Num[i]>cri)
            {
                cri=Num[i];
            }
        }
    }
    printf("%d\n",cri);
}
int main()
{
    Tree temp;
    int i,j;
    int x,y;
    long long z;
    while(scanf("%d%d%d",&n,&m,&L))
      {
          for(i=1;i<=m;i++)
          {
              scanf("%d%d%lld",&x,&y,&z);
              temp.l=x;
              temp.r=y;
              temp.co=z;
              T.push_back(temp);
              temp.l=y;
              temp.r=x;
              temp.co=z;
              T.push_back(temp);
          }
          for(i=1;i<=n;i++)
          {
              scanf("%d",&Num[i]);
          }
          Solu();
          T.clear();
      }
    return 0;
}

