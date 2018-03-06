#include <map>
#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
set<int> Rel[1000010];

int n,m;
int q;
int main()
{
    while(EOF!=scanf("%d%d",&n,&m))
    {
        for(int i=0;i<=n;i++)
        {
            Rel[i].clear();
        }
        scanf("%d",&q);
        for(int i=0;i<q;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            if(Rel[x].count(y)) printf("NO\n");
            else{
                Rel[x].insert(y);
                printf("YES\n");
            }
        }
    }
    return 0;
}

