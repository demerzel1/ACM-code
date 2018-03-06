#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#define max1 1000005
using namespace std;

vector<int>x[max1];
int main()
{  int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int k,u,v,c=0;
        scanf("%d",&k);
        for(int i=0;i<k;i++){
           scanf("%d%d",&u,&v);
           if(u<1||v<1||u>n||v>m) printf("NO\n");
           else{c=0;
          for(int i=0;i<x[u].size();i++)
          {
              if(v==x[u][i])
              { printf("NO\n");c=1;
               break;}
          }
           if(c==0)
          {
            x[u].push_back(v);
            printf("YES\n");
          }
        }

    } for(int i=1;i<=n;i++)
        {
            if(x[i].size()) x[i].clear();
        }}
    return 0;
}

