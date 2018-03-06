#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#include <functional>
#include <cmath>
#include <memory.h>
#include <cstdio>
#include <sstream>
#include <set>
using namespace std;

map <int,set<int> > gx;


int main()
{
    int x,y;
    while(scanf("%d%d",&x,&y)!=EOF)
    {
        gx.clear();
        int times,px,py;
        scanf("%d",&times);
        for(int i=0;i<times;i++)
        {
            scanf("%d%d",&px,&py);
            if(gx[px].count(py)==1)
                printf("NO\n");
            else
            {
                gx[px].insert(py);
                printf("YES\n");
            }
        }
    }
    return 0;
}

