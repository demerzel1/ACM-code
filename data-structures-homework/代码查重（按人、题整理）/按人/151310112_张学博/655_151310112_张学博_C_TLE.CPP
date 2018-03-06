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
map<int,vector<int> >mp;
int n,m,q;
int main()
{
    while(scanf("%d%d",&n,&m)&&n!=0&&m!=0)
    {
        mp.clear();
        scanf("%d",&q);
        int x,y;
        for(int i=0;i<q;i++)
        {
            scanf("%d%d",&x,&y);
            vector<int>::iterator it;
            it=find(mp[x].begin(),mp[x].end(),y);
            if(it==mp[x].end())
            {
                mp[x].push_back(y);
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }
    return 0;
}

