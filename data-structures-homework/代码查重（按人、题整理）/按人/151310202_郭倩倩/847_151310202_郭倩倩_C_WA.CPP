#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#define max 1000005
using namespace std;
int x[max],y[max];
int main()
{  int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    { memset(x,0,sizeof(x));
      memset(y,0,sizeof(y));
        int k,u,v;
        scanf("%d",&k);
        for(int i=0;i<k;i++){
           scanf("%d%d",&u,&v);
           if(x[u]==1&&y[v]==1)
           {
             printf("NO\n");
           }
           else if(u>n||v>m||u<1||v<1) printf("NO\n");
           else
            {
            printf("YES\n");
               x[u]=1;y[v]=1;
           }
        }
    }
    return 0;
}

