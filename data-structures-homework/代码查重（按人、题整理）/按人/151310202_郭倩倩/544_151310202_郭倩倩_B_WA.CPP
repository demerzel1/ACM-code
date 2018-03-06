#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#define max 1010
using namespace std;
long long int value[max];
int num[max][max];
bool chage[max];
int n,m,l,max1;
void getnum(int k){
    chage[k]=true;
  for(int i=1;i<=n;i++)
  {
      if(chage[i]!=true&&num[k][i]!=0)
      {
          if(l-num[k][i]>=0)
          {
              l-=num[k][i];
              if(max1<value[i]) max1=value[i];
              if(l>0)
                getnum(i);
              if(l==0) return;
              l+=num[k][i];
          }
          else return;
      }
  }
}
int main()
{  int u,v,c;
    while(scanf("%d%d%d",&n,&m,&l)!=EOF)
    {  max1=0;
    memset(num,0,sizeof(num));
    memset(value,0,sizeof(value));
       for(int i=0;i<m;i++)
       {
         scanf("%d%d%d",&u,&v,&c);
         num[u][v]=c;
       }
       for(int i=1;i<=n;i++)
       {
           scanf("%d",&u);
           value[i]=u;
           num[i][i]=0;
           chage[i]=false;
       }
       max1=value[1];
       getnum(1);
       printf("%d\n",max1);
    }
    return 0;
}

