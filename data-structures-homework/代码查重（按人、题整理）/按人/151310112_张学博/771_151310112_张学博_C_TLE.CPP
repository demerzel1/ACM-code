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
vector<int> a;
vector<int> b;
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
            if(find(a.begin(),a.end(),x)!=a.end()&&find(b.begin(),b.end(),y)!=b.end())
            {
                printf("NO\n");
            }
            else
            {
                a.push_back(x);
                b.push_back(y);
                printf("YES\n");
            }
        }
    }

    return 0;
}

