#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;
set<int>  S[1000002];
int n,m;
int main()
{
    int z;
    int x,y;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        scanf("%d",&z);
        int i;
        for(i=1;i<=z;i++)
        {
            scanf("%d%d",&x,&y);
            if(S[x].count(y))
            {
                printf("NO\n");
            }
            else
            {
                S[x].insert(y);
                printf("YES\n");
            }
        }
        for(i=1;i<=n;i++)
        {
            if(!S[i].empty())
            {
                S[i].clear();
            }
        }
    }

    return 0;
}

