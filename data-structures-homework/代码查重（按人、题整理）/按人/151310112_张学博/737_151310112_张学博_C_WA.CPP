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
map<int,int> a;
map<int,int> b;
int n,m,q;
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        a.clear();
        b.clear();
        scanf("%d",&q);
        int x,y;
        for(int i=0;i<q;i++)
        {
            scanf("%d%d",&x,&y);
            if(a.count(x)!=0&&b.count(y)!=0)
            {
                printf("NO\n");
            }
            else
            {
                a[x]=1;
                b[y]=1;
                printf("YES\n");
            }
        }
    }

    return 0;
}

