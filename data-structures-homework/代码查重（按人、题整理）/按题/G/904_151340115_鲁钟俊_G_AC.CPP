#include <iostream>
#include <math.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <map>
#include <cstring>
#include <queue>
#include <sstream>

using namespace std;

int n,m,k;
int g[105][105];
int link[105];
int use[105];

int can(int t)
{
    for(int i=1;i<=m;i++)
    {
        if(g[t][i]==1&&use[i]==0)
        {
            use[i]=1;
            if(link[i]==-1||can(link[i]))
            {
                link[i]=t;
                return 1;
            }
        }
    }
    return 0;
}

void MaxMatch()
{
    int i,num=0;
    memset(link,-1,sizeof(link));
    for(i=1;i<=n;i++)
    {
        memset(use,0,sizeof(use));
        if(can(i))  num++;
    }
    cout<<num<<endl;
}

int main()
{
    int x,y;
    while(cin>>n>>m)
    {
        memset(g,0,sizeof(g));
        cin>>k;
        for(int i=0;i<k;i++)
        {
            cin>>x>>y;
            g[x][y]=1;
        }
        MaxMatch();

    }
    return 0;
}

