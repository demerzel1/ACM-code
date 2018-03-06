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
map<int,vector<int> >p;
int n,m,q;
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        p.clear();
       scanf("%d",&q);
       int x,y;
       for(int i=0;i<q;i++)
       {
           scanf("%d%d",&x,&y);
           if(p[x].size()==0)
           {
               p[x].push_back(y);
               printf("YES\n");
           }
           else
           {
               if(find(p[x].begin(),p[x].end(),y)!=p[x].end())
               {
                   printf("NO\n");
               }
               else
               {
               p[x].push_back(y);
               printf("YES\n");
               }
           }
       }
    }

    return 0;
}

